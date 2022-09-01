#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int>dp(300, 0);

int main() {
	cin >> n;
	v = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = v[0];
	dp[1] = v[0]+v[1];
	dp[2] = max(v[0],v[1])+v[2];

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
	}

	cout << dp[n-1];
}