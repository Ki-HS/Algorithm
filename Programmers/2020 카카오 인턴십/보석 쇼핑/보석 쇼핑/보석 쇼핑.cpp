#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dp[100001];

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int ans = 100001;
    int size = gems.size();
    map<string, int> g;
    for (string t : gems)g[t];
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (dp[i].size() == g.size()) { break; }
            dp[i][gems[j]]=j;
        }
    }
    int i = 0;
    int c;
    int tmp = 0;
    for (; i < size; i++) {
        int t = dp[i].size();
        if (ans > t) { c = i; ans=tmp = t; }
    }

    return { c, tmp - c - 1 };
}

int main() {
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
}