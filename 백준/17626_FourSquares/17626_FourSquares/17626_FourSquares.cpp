#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 4; i <= n; i++) {
		int sq = sqrt(i);
		int min = 4;
		for (int j = sq; j >= 1; j--) {
			min = min <= dp[i - j * j] ? min : dp[i - j * j];
		}
		dp[i] = min;
	}
	cout << dp[n];
}