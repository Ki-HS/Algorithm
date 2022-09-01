#include <iostream>
#include <string>
#include <string.h>
using namespace std;
long long dp[1001][1001] = { 0, };

int main() {
	string a;
	string b;

	cin >> a;
	cin >> b;

	string lsc;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[a.size()][b.size()];

	return 0;
}