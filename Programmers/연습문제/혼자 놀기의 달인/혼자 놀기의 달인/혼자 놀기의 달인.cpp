#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    int idx = 0;

    vector<bool> s(cards.size(), true);
    int cur = 0;
    while (find(s.begin(), s.end(), true) != s.end()) {
        while (true) {
            if (s[cur]) {
                v[idx]++;
                s[cur] = false;
                cur = cards[cur] - 1;
            }
            else break;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i]) {
                cur = cards[i] - 1;
                idx++;
                v.push_back(0);
                break;
            }
        }
    }
    int a = *max_element(v.begin(), v.end());
    v.erase(max_element(v.begin(), v.end()));
    if (v.empty()) return 0;
    int b = *max_element(v.begin(), v.end());
    v.erase(max_element(v.begin(), v.end()));


    return a * b;
}

int main() {
    cout << solution({ 2,3,4,1 });
}