#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int solution(int n, vector<vector<int>> w) {
    int answer = 999999;
    map<int, vector<int>> m;
    for (int i = 0; i < n - 1; i++) {
        m[w[i][0]].push_back(w[i][1]);
        m[w[i][1]].push_back(w[i][0]);
    }

    for (int i = 0; i < n - 1; i++) {
        vector<int> t = w[i];

        int first = 0, second = 0;

        queue<int> q;
        q.push(t[0]);
        vector<bool> v(n+1, false);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            v[x] = true;
            first++;
            for (int j = 0; j < m[x].size(); j++) {
                if (m[x][j] != t[1] && v[m[x][j]] == false) q.push(m[x][j]);
            }
        }

        q.push(t[1]);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            v[x] = true;
            second++;
            for (int j = 0; j < m[x].size(); j++) {
                if (m[x][j] != t[0] && v[m[x][j]] == false) q.push(m[x][j]);
            }
        }
        answer = abs(first - second) > answer ? answer : abs(first - second);
    }


    return answer;
}

int main() {
    cout<<solution(4, { {1, 2},{2, 3},{3, 4} });
}