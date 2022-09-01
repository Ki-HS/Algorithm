#include <iostream>
#include <vector>
using namespace std;

int n, k;

unsigned long long int cnt = 0;
unsigned long long num = 1000000000;
unsigned long long dp[201][201] = { 0, };

unsigned long long solution(int a, int b) {
	for (int i = 0; i <= a; i++)dp[i][1] = 1;
	
	if (dp[a][b])return dp[a][b];
	
	for (int i = 0; i <= a; i++)dp[a][b] += solution(a - i, b - 1) % num;
	
	dp[a][b] %= num;
	return dp[a][b];
}

int main() {
	cin >> n >> k;

	cout << solution(n, k);
}