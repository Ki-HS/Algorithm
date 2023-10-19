#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define inf 999999
using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> graph(n, vector<int>(n, inf));

    for (int i = 0; i < n; i++)graph[i][i] = 0;
    for (auto v : results) {
        graph[v[0]-1][v[1]-1] = 1;
        graph[v[1] - 1][v[0] - 1] = 2;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] == graph[k][j]&& graph[i][k]!=inf) graph[i][j] = graph[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        bool s = true;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == inf) {
                s = false;
                break;
            }
        }

        if (s)answer++;
    }
    return answer;
}

int main() {
    cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}