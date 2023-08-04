#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

int solution(string skill, vector<string> skill_trees) {

    int answer = 0;

    queue<char> stk;
    queue<char> tmp;
    map<char, int> m;
    for (char c : skill) { stk.push(c); m[c]++; }

    for (string s : skill_trees) {
        bool flag = false;
        tmp = stk;
        int pos = 0;
        for (char c : s) {
            if (m[c]) {
                char t = tmp.front();
                if (c == t) {
                    tmp.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) answer++;
    }

    return answer;
}

int main() {
    cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
}