#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int ans = 0;
    vector<int>v(n+1, 1);
    v[0] = 0;
    v[1] = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (v[i]==0)continue;
        for (int j = i * i; j <= n; j += i) { v[j] = 0; }
   }
    for(int i=2; i<=n; i++)
        if(v[i])ans++;

    return ans;
}

int main() {
    cout << solution(10);
}