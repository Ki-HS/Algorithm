#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int suc(int N, int i) {
    string t = to_string(N);
    string s = "";
    i++;
    while (i--) {
        s += t;
    }

    return stoi(s);
}

int solution(int N, int number) {
    int answer = 0;
    if (N == number)return 1;
   
    map<int, int> m;
    vector<map<int, int>> dp(8,m);
    
    dp[0][N];

    for (int i = 1; i < 8; i++) {
        int succeed = suc(N, i);
        dp[i][succeed]=1;

        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                if (j + k + 1 != i)continue;
                for (auto n : dp[j]) {
                    for (auto m : dp[k]) {
                        int t = n.first;
                        int b = m.first;
                        
                        dp[i][t + b] = 1;
                        dp[i][t * b] = 1;

                        if(t-b>0)dp[i][t - b] = 1;
                        if(t/b>0)dp[i][t / b] = 1;

                        
                    }
                   
                }
            }
           }
        
        if (dp[i][number])
            return i + 1;
        dp[i].erase(number);
    }


    return -1;
}

int main() {
    cout << solution(5, 31168);
}