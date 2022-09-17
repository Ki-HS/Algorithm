#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    int idx = 0;
    int cnt = 0;
    while (1) {
        for (int i = idx; i < p.size(); i++) {
            p[i] += s[i];
        }
        if (p[idx] >= 100) {
            while (idx<p.size()&&p[idx] >= 100)idx++;
            answer.push_back(idx-cnt);
            cnt = idx;
        }
        if (idx >= p.size())break;
    }
    return answer;
}

int main() {
    vector<int> a = {93,30,55,60,40,65};
    vector<int> b = { 1,30,5,10,60,7};
    vector<int>v = solution(a, b);
    for (auto i : v)cout << i << ' ';
}