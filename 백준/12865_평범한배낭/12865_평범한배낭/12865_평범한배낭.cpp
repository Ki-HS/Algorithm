#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
	int dp[110][100010] = { 0, };

int main() {
	cin >> n >> k;

	int a, b;
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= v[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

}