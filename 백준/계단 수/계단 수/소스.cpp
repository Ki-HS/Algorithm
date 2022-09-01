#include <iostream>
#include <string.h>
using namespace std;
int n;
int full = (1 << 10) - 1;
int stair[101][11][1 << 10];

int stairNum(int i, int j, int k) {
	int& result = stair[i][j][k];
	if (result != -1)return result;

	if (i == n) {
		if (k == full) return 1;
		else return 0;
	}

	result = 0;
	if (j == 0) {
		result += stairNum(i + 1, j + 1, k | (1 << (j + 1)));
		result %= 1000000000;
	}
	else if (j == 9) {
		result += stairNum(i + 1, j - 1, k | (1 << (j - 1)));
		result %= 1000000000;
	}
	else {
		result += stairNum(i + 1, j - 1, k | (1 << (j - 1))) + stairNum(i + 1, j + 1, k | (1 << (j + 1)));
		result %= 1000000000;
	}

	return result %= 1000000000;
}

int main() {
	cin >> n;
	memset(stair, -1, sizeof(stair));

	int sum = 0;

	for (int i = 1; i < 10; i++) {
		int k = 1 << i;
		sum += stairNum(1, i, k);
		sum%= 1000000000;
	}

	cout << sum;
}