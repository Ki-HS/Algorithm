#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    int cnt = 0;
    int sb = 0;
    
    vector<vector<int>> dp(100001, vector<int>(2, 0));

    for (int i = 1; i <= target; i++) {
        if (i <= 20 ||i== 50) dp[i] = { 1,1 };
        else if (i <= 40 && i % 2 == 0)dp[i] = { 1,0 };
        else if (i <= 60 && i % 3 == 0)dp[i] = { 1,0 };
        else if (i > 50 && i <= 70) dp[i] = { 2,2 }; 
        else if (i < 70) {
            if(i<40) dp[i] = { 2,2 };
            else dp[i] = { 2,1 };
        }
        else {
            if (dp[i - 60][0] == dp[i - 50][0]) {
                dp[i][0] = dp[i - 50][0] + 1;
                dp[i][1] = max(dp[i - 60][1], dp[i - 50][1] + 1);
            }
            else if (dp[i - 60][0] < dp[i - 50][0]) {
                dp[i][0] = dp[i - 60][0] + 1;
                dp[i][1] = dp[i - 60][1];
            }
            else {
                dp[i][0] = dp[i - 50][0] + 1;
                dp[i][1] = dp[i - 50][1] + 1;
            }
        }


    }

    return dp[target];
}

int main() {
    solution(280);
}