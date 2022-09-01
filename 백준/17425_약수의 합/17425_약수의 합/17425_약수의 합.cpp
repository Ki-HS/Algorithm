#include <iostream>

using namespace std;

long long num[1000001];
long long dp[1000001] = { 0, };
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	for (int i = 0; i <= 1000000; i++) {
		num[i] = 1;
	}
	cin >> n;
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 1; j*i <= 1000000; j++) {
			num[i * j] += i;
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		dp[i] += dp[i - 1] + num[i];
	}


	for (int k = 0; k < n; k++) {
		long long t;
		cin >> t;

		cout << dp[t]<<"\n";
	}
	
}
