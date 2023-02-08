#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    vector<char> v(26, 'a');
    for (int i = 1; i < 26; i++) v[i] += i;

    for (char c : skip) {
        int t = find(v.begin(), v.end(), c) - v.begin();
        v.erase(v.begin() + t);
    }
    for (char i : s) {
        int idx = find(v.begin(), v.end(), i) - v.begin();
        if (v.size() <= idx + index)i = v[(idx+index)%(v.size())];
        else i = v[idx+index];
        answer += i;
    }
    return answer;
}

int main() {
    cout << solution("aukks", "wbqd", 5);
}