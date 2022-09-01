#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int xMax = 0, yMax = 0;
    int t;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            t = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = t;
        }
        if (xMax < sizes[i][0])xMax = sizes[i][0];
        if (yMax < sizes[i][1])yMax = sizes[i][1];
    }
    answer = xMax * yMax;
    return answer;
}