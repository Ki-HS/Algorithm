#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//접근 방법
//꼭대기에서 바닥까지의 경로 중 최대 값이 되도록 할 때,
//처음에는 문제처럼 꼭대기에서 접근하려고 했었다.
//그렇게 했을 경우 한 쪽을 모두 탐색후 다른 쪽 탐색하므로 효율적이지 못한다고 생각했다.
//그래서 반대로 바닥에서 꼭대기로 탐색을 진행했다.
//부모가 두 자식 중 큰 것을 고르는 방식으로 바닥에서 꼭대기까지 계산하면 쉽게 해결할 수 있다.

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}