#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    for (string s : keymap) {
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 0)m[s[i]] = i + 1;
            else if (m[s[i]] > i + 1)m[s[i]] = i + 1;
        }
    }

    // for(auto i = m.begin(); i!=m.end(); i++){
    //     answer.push_back(i->second);
    // }

    bool cond = true;
    for (string s : targets) {
        cond = true;
        int i = 0;
        for (char c : s) {
            if (m[c] == 0) { answer.push_back(-1); cond = false; break; }
            i += m[c];
        }
        if (cond)answer.push_back(i);
    }

    return answer;
}