#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<long long>> stair(100, vector<long long>(11,0));

	stair[0][10] = 9;
	for (int i = 0; i < 10; i++) {
		stair[0][i] = 1;
	}
	long long cnt;
	for (int i = 1; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				stair[i][j] += stair[i-1][j + 1] % 1000000000;
			}
			else if (j == 9) {
				stair[i][j] += stair[i - 1][j - 1] % 1000000000;
			}
			else {
				stair[i][j] += (stair[i - 1][j + 1]+ stair[i - 1][j - 1])%1000000000;
			}
			if (j) cnt += stair[i][j];
		}
		stair[i][10] = cnt;
	}
	long long result = stair[n - 1][10] % 1000000000;
	cout << result;
}