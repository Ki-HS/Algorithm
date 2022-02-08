#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	int connected;
	cin >> n;
	cin >> connected;
	int a, b;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<bool> visited(n, false);
	for (int i = 0; i < connected; i++) {
		cin >> a;
		cin >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	int cnt = -1;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int w = q.front();
		cnt++;
		
		q.pop();
		for (int i = 0; i < graph[w].size(); i++) {
			if (graph[w][i] && !visited[i]) { q.push(i); visited[i] = true;
			}
		}
	}
	cout << cnt;
}