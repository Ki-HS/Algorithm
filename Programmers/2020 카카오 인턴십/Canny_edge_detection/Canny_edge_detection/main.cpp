#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned char BYTE;
#define src1 "Suzie_CIF_352x288."

class RGBBYTE
{
public:
    BYTE b;
    BYTE g;
    BYTE r;

public:
    RGBBYTE() : b(0), g(0), r(0) {}
    RGBBYTE(BYTE gray) : b(gray), g(gray), r(gray) {}
    RGBBYTE(const BYTE& _r, const BYTE& _g, const BYTE& _b) : b(_b), g(_g), r(_r) {}
};
const double PI = 3.14159265358979323846;
const float PI_F = 3.14159265358979323846f;
#define CHECK_WEAK_EDGE(x, y) \
    if (pEdge[y][x] == WEAK_EDGE) { \
        pEdge[y][x] = STRONG_EDGE; \
        strong_edges.push_back(IppPoint(x, y)); \
    }

template<typename T>
class IppImage
{
public:
    int width;  // ������ ���� ũ��(�ȼ� ����)
    int height; // ������ ���� ũ��(�ȼ� ����)
    T** pixels; // �ȼ� ������

public:
    // �����ڿ� �Ҹ���
    IppImage();
    IppImage(int w, int h);
    IppImage(const IppImage<T>& img);
    ~IppImage();

    // �̹��� ������ �Ҹ�
    void CreateImage(int w, int h);
    void DestroyImage();

    // �ȼ� �� ����
    T* GetPixels() const {
        if (pixels) return pixels[0];
        else return NULL;
    }
    T** GetPixels2D() const { return pixels; }

    // ġȯ ������ ������
    IppImage<T>& operator=(const IppImage<T>& img);
    template<typename U> IppImage<T>& operator=(const IppImage<U>& img);

    // ���� ���� ��ȯ
    int GetWidth()   const { return width; }
    int GetHeight()  const { return height; }
    int GetSize()    const { return width * height; }
    bool IsValid()   const { return (pixels != NULL); }
};

typedef IppImage<BYTE>     IppByteImage;
typedef IppImage<int>      IppIntImage;
typedef IppImage<float>    IppFloatImage;
typedef IppImage<double>   IppDoubleImage;
typedef IppImage<RGBBYTE>  IppRgbImage;

template<typename T>
void IppImage<T>::CreateImage(int w, int h)
{
    DestroyImage();

    width = w;
    height = h;

    pixels = new T * [sizeof(T*) * height];
    pixels[0] = new T[sizeof(T) * width * height];

    for (int i = 1; i < height; i++)
        pixels[i] = pixels[i - 1] + width;

    memset(pixels[0], 0, sizeof(T) * width * height); // �ȼ� �� �ʱ�ȭ
}

template<typename T>
void IppImage<T>::DestroyImage()
{
    if (pixels != NULL) {
        delete[] pixels[0];
        delete[] pixels;
        pixels = NULL;
    }

    width = height = 0;
}


class IppPoint
{
public:
    int x;
    int y;

public:
    IppPoint() : x(0), y(0) {}
    IppPoint(int _x, int _y) : x(_x), y(_y) {}
};

void IppFilterGaussian(IppByteImage& imgSrc, IppFloatImage& imgDst, float sigma)
{
    register int i, j, k, x;

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h);

    BYTE** pSrc = imgSrc.GetPixels2D();
    float** pDst = imgDst.GetPixels2D();

    //-------------------------------------------------------------------------
    // 1���� ����þ� ����ũ & �Ǽ� ������ ���� ���� �̹��� ����
    //-------------------------------------------------------------------------

    int dim = static_cast<int>(2 * 4 * sigma + 1.0);
    if (dim < 3) dim = 3;
    if (dim % 2 == 0) dim++;
    int dim2 = dim / 2;

    IppFloatImage imgMask(dim, 1);
    float* pMask = imgMask.GetPixels();

    for (i = 0; i < dim; i++)
    {
        x = i - dim2;
        pMask[i] = exp(-(x * x) / (2 * sigma * sigma)) / (sqrt(2 * PI_F) * sigma);
    }

    IppFloatImage imgBuf(w, h);
    float** pBuf = imgBuf.GetPixels2D();

    //-------------------------------------------------------------------------
    // ���� ���� ����ũ ����
    //-------------------------------------------------------------------------

    float sum1, sum2;
    for (i = 0; i < w; i++)
        for (j = 0; j < h; j++)
        {
            sum1 = sum2 = 0.f;

            for (k = 0; k < dim; k++)
            {
                x = k - dim2 + j;

                if (x >= 0 && x < h)
                {
                    sum1 += pMask[k];
                    sum2 += (pMask[k] * pSrc[x][i]);
                }
            }

            pBuf[j][i] = sum2 / sum1;
        }

    //-------------------------------------------------------------------------
    // ���� ���� ����ũ ����
    //-------------------------------------------------------------------------

    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
        {
            sum1 = sum2 = 0.f;

            for (k = 0; k < dim; k++)
            {
                x = k - dim2 + i;

                if (x >= 0 && x < w)
                {
                    sum1 += pMask[k];
                    sum2 += (pMask[k] * pBuf[j][x]);
                }
            }

            pDst[j][i] = sum2 / sum1;
        }
}

void IppEdgeCanny(IppByteImage& imgSrc, IppByteImage& imgEdge, float sigma, float th_low, float th_high)
{
    register int i, j;

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    // 1. ����þ� ���͸�

    IppFloatImage imgGaussian(w, h);
    IppFilterGaussian(imgSrc, imgGaussian, sigma);

    // 2. �׷����Ʈ ���ϱ� (ũ�� & ����)

    IppFloatImage imgGx(w, h); // gradient of x
    IppFloatImage imgGy(w, h); // gradient of y
    IppFloatImage imgMag(w, h); // magnitude of gradient

    float** pGauss = imgGaussian.GetPixels2D();
    float** pGx = imgGx.GetPixels2D();
    float** pGy = imgGy.GetPixels2D();
    float** pMag = imgMag.GetPixels2D();

    for (j = 1; j < h - 1; j++)
        for (i = 1; i < w - 1; i++)
        {
            pGx[j][i] = -pGauss[j - 1][i - 1] - 2 * pGauss[j][i - 1] - pGauss[j + 1][i - 1]
                + pGauss[j - 1][i + 1] + 2 * pGauss[j][i + 1] + pGauss[j + 1][i + 1];
            pGy[j][i] = -pGauss[j - 1][i - 1] - 2 * pGauss[j - 1][i] - pGauss[j - 1][i + 1]
                + pGauss[j + 1][i - 1] + 2 * pGauss[j + 1][i] + pGauss[j + 1][i + 1];

            pMag[j][i] = sqrt(pGx[j][i] * pGx[j][i] + pGy[j][i] * pGy[j][i]);
        }

    // 3. ���ִ� ����
    // ������ �ִ븦 ���԰� ���ÿ� ���� �Ӱ谪�� �����Ͽ� strong edge�� weak edge�� ���Ѵ�.

    imgEdge.CreateImage(w, h);
    BYTE** pEdge = imgEdge.GetPixels2D();

    enum DISTRICT { AREA0 = 0, AREA45, AREA90, AREA135, NOAREA };

    const BYTE STRONG_EDGE = 255;
    const BYTE WEAK_EDGE = 128;

    std::vector<IppPoint> strong_edges;

    float ang;
    int district;
    bool local_max;
    for (j = 1; j < h - 1; j++)
        for (i = 1; i < w - 1; i++)
        {
            // �׷����Ʈ ũ�Ⱑ th_low���� ū �ȼ��� ���ؼ��� ������ �ִ� �˻�
            // ������ �ִ��� �ȼ��� ���ؼ��� ���� ���� �Ǵ� ���� ������ ����
            if (pMag[j][i] > th_low)
            {
                // �׷����Ʈ ���� ��� (4�� ����)
                if (pGx[j][i] != 0.f)
                {
                    ang = atan2(pGy[j][i], pGx[j][i]) * 180 / PI_F;
                    if (((ang >= -22.5f) && (ang < 22.5f)) || (ang >= 157.5f) || (ang < -157.5f))
                        district = AREA0;
                    else if (((ang >= 22.5f) && (ang < 67.5f)) || ((ang >= -157.5f) && (ang <
                        -112.5f)))
                        district = AREA45;
                    else if (((ang >= 67.5) && (ang < 112.5)) || ((ang >= -112.5) && (ang < -67.5)))
                        district = AREA90;
                    else
                        district = AREA135;
                }
                else
                    district = AREA90;

                // ������ �ִ� �˻�
                local_max = false;
                switch (district)
                {
                case AREA0:
                    if ((pMag[j][i] >= pMag[j][i - 1]) && (pMag[j][i] > pMag[j][i + 1]))
                        local_max = true;
                    break;
                case AREA45:
                    if ((pMag[j][i] >= pMag[j - 1][i - 1]) && (pMag[j][i] > pMag[j + 1][i + 1]))
                        local_max = true;
                    break;
                case AREA90:
                    if ((pMag[j][i] >= pMag[j - 1][i]) && (pMag[j][i] > pMag[j + 1][i]))
                        local_max = true;
                    break;
                case AREA135:
                default:
                    if ((pMag[j][i] >= pMag[j - 1][i + 1]) && (pMag[j][i] > pMag[j + 1][i - 1]))
                        local_max = true;
                    break;
                }

                // ���� ������ ���� ���� ����
                if (local_max)
                {
                    if (pMag[j][i] > th_high)
                    {
                        pEdge[j][i] = STRONG_EDGE;
                        strong_edges.push_back(IppPoint(i, j));
                    }
                    else
                        pEdge[j][i] = WEAK_EDGE;
                }
            }
        }

    // 4. �����׸��ý� ���� Ʈ��ŷ

    while (!strong_edges.empty())
    {
        IppPoint p = strong_edges.back();
        strong_edges.pop_back();

        int x = p.x, y = p.y;

        // ���� ���� �ֺ��� ���� ������ ���� ����(���� ����)�� ����
        CHECK_WEAK_EDGE(x + 1, y)
            CHECK_WEAK_EDGE(x + 1, y + 1)
            CHECK_WEAK_EDGE(x, y + 1)
            CHECK_WEAK_EDGE(x - 1, y + 1)
            CHECK_WEAK_EDGE(x - 1, y)
            CHECK_WEAK_EDGE(x - 1, y - 1)
            CHECK_WEAK_EDGE(x, y - 1)
            CHECK_WEAK_EDGE(x + 1, y - 1)
    }

    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
        {
            // ������ ���� ������ �����ִ� �ȼ��� ��� ������ �ƴ� ������ �Ǵ�
            if (pEdge[j][i] == WEAK_EDGE) pEdge[j][i] = 0;
        }
}
int main() {

    FILE* input;
    int width = 352;
    int height = 288;
    input = fopen(src1, "rb");
    if (!input) {
        cout << "file not exists";
        return 0;
    }
    BYTE image[325][288];
    fread(image, sizeof(char), width * height, input);
    IppByteImage src(352,288);
    IppByteImage edge;
}