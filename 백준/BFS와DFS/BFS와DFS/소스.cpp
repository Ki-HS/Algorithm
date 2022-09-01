#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<int> g[], int v, int s) {
	queue<int> q;
	q.push(s);
	vector<bool> visit(v, 0);
	visit[s] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x+1 << " ";
		for (unsigned int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			if (!visit[y]) {
				q.push(y);
				visit[y] = true;
			}
		}
	}
	cout << "\n";
}
void dfs_tra(vector<int> g[], int s, vector<bool>visit) {
	visit[s] = true;
	cout << s + 1 << " ";
	
	for (unsigned int i = 0; i < g[s].size(); i++) {
		if (!visit[g[s][i]]) { 
			dfs_tra(g, g[s][i], visit);
			return;
		}
	}

}
void dfs(vector<int> g[], int v, int s) {
	vector<bool> visit(v, false);
	dfs_tra(g, s-1, visit);
	cout << "\n";
}



int main() {
	int v, e, s;//정점, 간선, 시작노드
	cin >> v >> e >> s;
	vector<int> g[1000];
	while (e--) {
		int t1, t2;
		cin >> t1 >> t2;
		g[t1-1].push_back(t2-1);
		g[t2-1].push_back(t1-1);
		sort(g[t1 - 1].begin(), g[t1 - 1].end());
		sort(g[t2 - 1].begin(), g[t2 - 1].end());
	}
	dfs(g, v, s);
	bfs(g, v, s-1);
}