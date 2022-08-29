#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> v1;
	vector<vector<char>> v2;
	v1 = vector<vector<char>>(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v1[i][j];
	v2 = v1;
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	char temp = v1[0][0];
	int cnt = 0;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v1[i][j] != '0') {
				temp = v1[i][j];
				q1.push(make_pair(i, j));
				v1[i][j] = '0';
				while (!q1.empty()) {
					int x = q1.front().first;
					int y = q1.front().second;
					q1.pop();
					if (x != 0 && v1[x - 1][y] == temp) {
						q1.push(make_pair(x - 1, y));
						v1[x-1][y] = '0';
					}
					if (x != n - 1 && v1[x + 1][y] == temp) {
						q1.push(make_pair(x + 1, y));
						v1[x+1][y] = '0';
					}
					if (y != 0 && v1[x][y - 1] == temp) {
						q1.push(make_pair(x, y - 1));
						v1[x][y-1] = '0';
					}
					if (y != n - 1 && v1[x][y + 1] == temp) {
						q1.push(make_pair(x, y + 1));
						v1[x][y+1] = '0';
					}
				}
				a++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v2[i][j] == 'B') {
				temp = v2[i][j];
				v2[i][j] = '0';
				q2.push(make_pair(i, j));
				while (!q2.empty()) {
					int x = q2.front().first;
					int y = q2.front().second;
					q2.pop();
					v2[x][y] = '0';
					if (x != 0 && v2[x - 1][y] == temp) {
						q2.push(make_pair(x - 1, y));
						v2[x-1][y] = '0';
					}
					if (x != n - 1 && v2[x + 1][y] == temp) {
						q2.push(make_pair(x + 1, y));
						v2[x+1][y] = '0';
					}
					if (y != 0 && v2[x][y - 1] == temp) {
						q2.push(make_pair(x, y - 1));
						v2[x][y-1] = '0';
					}
					if (y != n - 1 && v2[x][y + 1] == temp) {
						q2.push(make_pair(x, y + 1));
						v2[x][y+1] = '0';
					}
				}
				b++;
			}
			else if (v2[i][j] == 'R' || v2[i][j] == 'G') {
				q2.push(make_pair(i, j));
				while (!q2.empty()) {
					int x = q2.front().first;
					int y = q2.front().second;
					v2[x][y] = '0';
					q2.pop();
					if (x != 0 && (v2[x - 1][y] == 'R' || v2[x - 1][y] == 'G')) {
						q2.push(make_pair(x - 1, y));
						v2[x-1][y] = '0';
					}
					if (x != n - 1 && (v2[x + 1][y] == 'R' || v2[x + 1][y] == 'G')) {
						q2.push(make_pair(x + 1, y));
						v2[x+1][y] = '0';
					}
					if (y != 0 && (v2[x][y - 1] == 'R' || v2[x][y - 1] == 'G')) {
						q2.push(make_pair(x, y - 1));
						v2[x][y-1] = '0';
					}
					if (y != n - 1 && (v2[x][y + 1] == 'R' || v2[x][y + 1] == 'G')) {
						q2.push(make_pair(x, y + 1));
						v2[x][y+1] = '0';
					}
				}
				b++;
			}
		}
	}

	cout << a << ' ' << b;
}