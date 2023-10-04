#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//���� ���
//����⿡�� �ٴڱ����� ��� �� �ִ� ���� �ǵ��� �� ��,
//ó������ ����ó�� ����⿡�� �����Ϸ��� �߾���.
//�׷��� ���� ��� �� ���� ��� Ž���� �ٸ� �� Ž���ϹǷ� ȿ�������� ���Ѵٰ� �����ߴ�.
//�׷��� �ݴ�� �ٴڿ��� ������ Ž���� �����ߴ�.
//�θ� �� �ڽ� �� ū ���� ���� ������� �ٴڿ��� �������� ����ϸ� ���� �ذ��� �� �ִ�.

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}