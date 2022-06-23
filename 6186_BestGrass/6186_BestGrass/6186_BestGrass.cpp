#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int c = 0;
void func(vector<vector<char>> &v, int x, int y) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	bool hor = false, ver=false;
	while (!q.empty()) {
		int col = q.front().first;
		int row = q.front().second;
		v[col][row] = '.';
		q.pop();

		if (col != n - 1 && v[col + 1][row] == '#') {
			q.push(make_pair(col + 1, row));
		}
		else if (row != m - 1 && v[col][row + 1] == '#') {
			q.push(make_pair(col, row + 1));
		}
	}
	c++;
}

int main() {
	cin >> n >> m;
	vector<vector<char>> v(n,vector<char>(m));

	char t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> t;
			v[i][j] = t;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '#') func(v, i, j);
		}
	}
	cout << c;
}