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
ó������ dfs�� Ǯ����.
������ ū ������ ȭ����� ���� ȭ����� ���ʷ� ����ϴµ�,
�̶�, ������ ū ȭ�� ���ϰ��� �ϴ� ������ �ϳ��� �� ��쿡 ���� 
DFS�� �����ؼ� ���Ѵٸ� ���� ���� ���� �� �������� �����ߴ�. 
������, ȭ���� ������ �������� ���ϰ����ϴ� ���� ũ�Ⱑ Ŀ������ �ð��� ������� ������ �����ߴ�.

�׷��� DP�� �̿��ߴ�.
*/