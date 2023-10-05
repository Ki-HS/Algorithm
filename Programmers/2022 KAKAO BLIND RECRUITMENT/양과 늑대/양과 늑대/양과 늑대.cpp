#include <string>
#include <vector>
#include <queue>
using namespace std;

//방문할 수 있는 곳을 재귀적으로 담아보자.

int answer = 0;
vector<int> node[17];

void dfs(int cur, int s, int w, queue<int> q, vector<int>info) {
    if (info[cur]) w++;
    else s++;
    if (s <= w) return;
    answer = answer < s ? s : answer;

    for (int i = 0; i < node[cur].size(); i++)
        q.push(node[cur][i]);

    for (int i = 0; i < q.size(); i++) {
        int nxt = q.front();
        q.pop();
        dfs(nxt, s, w, q, info);
        q.push(nxt);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    for (auto e : edges) {
        node[e[0]].push_back(e[1]);
    }
    queue<int>q;
    dfs(0, 0, 0, q, info);


    return answer;
}