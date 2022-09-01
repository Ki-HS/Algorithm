#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minusOne = 0, zero = 0, one = 0;
vector<vector<int>>v;
map<int, int> m;
bool check(int row, int col, int size) {
	int t = v[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (t != v[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solution(int row, int col, int size) {
	if (check(row, col, size)) {
		m[v[row][col]]++;
		return;
	}
	int s = size / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solution(row + i * s, col + j * s, s);
		}
	}
}

int main() {
	int n;
	cin >> n;
	v= vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}

	solution(0,0,n);

	cout << m[-1] << endl
		<< m[0] << endl
		<< m[1] << endl;
}