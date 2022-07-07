#include <iostream>
#include <vector>

using namespace std;

int blank = 0;

bool valuable(vector<vector<int>>& v, int x, int y, int val) {
	int sx = x / 3;
	int sy = y / 3;

	for (int i = 0; i < 9; i++) {
		if (v[i][y] == val)return false;
		if (v[x][i] == val)return false;
	}

	for (int i = sx * 3; i < sx * 3 + 3; i++) {
		for (int j = sy * 3; j < sy * 3 + 3; j++) {
			if (v[i][j]==val) return false;
		}
	}
	return true;
}

void solution(vector<vector<int>>& v, int t) {
	if (t == blank) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				if (!v[i][j]) {
					for (int k = 1; k <= 9; k++) {
						if (valuable(v, i, j, k)) {
							v[i][j] = k;
							solution(v,t + 1);
							v[i][j] = 0;
						}
						if (k == 9)return;
					}
				}
			}
		  }
	}
}

int main() {
	vector<vector<int>> v(9,vector<int>(9));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			if (!v[i][j]) blank++;
		}
	}

	solution(v, 0);
	
	
}