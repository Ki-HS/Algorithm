#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int dp[15] = { 1,1,2,5,0, };

    for (int i = 4; i <= 14; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}