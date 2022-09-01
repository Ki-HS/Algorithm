#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<bool> v(n, 0);
	vector<vector<int>> w(n, vector<int>());

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		w[a - 1].push_back(b - 1);
		w[b - 1].push_back(a - 1);
	}
	queue<int> q;

	int cnt = 0;

	while (find(v.begin(), v.end(), false) != v.end()) {
		auto iter = find(v.begin(), v.end(), false);
		int num = iter - v.begin();

		q.push(num);
		cnt++;
		while (!q.empty()) {
			if (!v[q.front()]) {
				for (int i = 0; i < w[q.front()].size(); i++) {
					if (!v[w[q.front()][i]])
						q.push(w[q.front()][i]);
				}
				v[q.front()] = true;
			}
			q.pop();
		}
	}
	cout << cnt;
}