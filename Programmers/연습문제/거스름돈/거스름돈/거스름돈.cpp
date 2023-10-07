#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define div 1000000007

using namespace std;

int ans = 0;

//void dfs(int cur, int n, vector<int> money) {
//    if (!n) {
//        ans++;
//        ans %= div;
//        return;
//    }
//    else if (n < 0) return;
//
//    if (cur == money.size())return;
//
//
//    for (int i = 0; money[cur] * i <= n; i++) {
//        dfs(cur + 1, n - (money[cur] * i), money);
//    }
//
//}
//
//int solution(int n, vector<int> money) {
//    int answer;
//
//    sort(money.begin(), money.end(), greater<int>());
//    dfs(0, n, money);
//    answer = ans % div;
//
//
//    return answer;
//}

int solution(int n, vector<int> money) {
	int answer;

	int dp[100001] = { 0, };

	dp[0] = 1;
	for (auto m : money) {
		for (int i = m; i <= n; i++) {
			dp[i] += dp[i - m];
		}
	}

	return dp[n];
}

int main() {
	cout << solution(5, { 1,2,5 });
}

/*
처음에는 dfs로 풀었다.
이유는 큰 단위의 화폐부터 작은 화폐까지 차례로 계산하는데,
이때, 단위가 큰 화폐를 구하고자 하는 값에서 하나씩 뺀 경우에 대해 
DFS를 진행해서 구한다면 답을 쉽게 구할 수 있으리라 생각했다. 
하지만, 화폐의 종류가 많아지고 구하고자하는 돈의 크기가 커질수록 시간이 길어지기 때문에 실패했다.

그래서 DP를 이용했다.
*/