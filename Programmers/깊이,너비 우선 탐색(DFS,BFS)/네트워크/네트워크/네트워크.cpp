#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computer) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!computer[i][i])continue;
        queue<int>q;
        q.push(i);
        while (!q.empty()) {
            int t = q.front();
            computer[t][t] = 0;
            q.pop();

            for (int j = 0; j < n; j++) {
                if (computer[t][j] && computer[j][j])
                    q.push(j);
            }
        }

        answer++;
    }
    return answer;
}