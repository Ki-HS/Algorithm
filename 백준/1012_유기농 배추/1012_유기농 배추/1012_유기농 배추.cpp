#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
int m, n, k;
int z = 0;
void baechu(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x != 0 && v[x - 1][y]) {
			q.push(make_pair(x - 1, y)); v[x-1][y] = 0;
		}
		if (x != m - 1 && v[x + 1][y]){
			q.push(make_pair(x + 1, y)); v[x+1][y] = 0;
		}
		if (y != 0 && v[x][y - 1]){
			q.push(make_pair(x, y - 1)); v[x][y-1] = 0;
		}
		if (y != n - 1 && v[x][y + 1]){
			q.push(make_pair(x, y + 1)); v[x][y+1] = 0;
		}
	}
	z++;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	int x, y;
	vector<vector<int>> nul;
	for (int i = 0; i < t; i++) {
		v = nul;
		cin >> m >> n >> k;
		v = vector<vector<int>>(m, vector<int>(n, 0));
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			v[x][y] = 1;
		}
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (v[a][b])baechu(a, b);
			}
		}
		cout << z << "\n";
		z = 0;
	}
}