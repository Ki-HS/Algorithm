#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i <= t.size() - p.size(); i++) {
        string s = t.substr(i, p.size());
        if (stoll(s) <= stoll(p))answer++;
    }

    return answer;
}

int main() {
    cout << solution("1032500220839878", "1032500220839878");
}