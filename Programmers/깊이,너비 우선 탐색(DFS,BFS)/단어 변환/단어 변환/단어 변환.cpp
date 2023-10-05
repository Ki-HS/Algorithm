#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define max 999999
int answer = max;
string b, t;
bool cmp(string a, string b) {
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])c++;
    }

    return c == a.size() - 1;
}

void dfs(string cur, vector<string> w, map<string, int> m, int c) {
    if (t == cur) {
        answer = answer < c ? answer : c;
        return;
    }

    m[cur] = 1;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == cur)continue;
        if (!m[w[i]] && cmp(cur, w[i])) 
            dfs(w[i], w, m, c + 1);
    }
}

int solution(string begin, string target, vector<string> words) {
    b = begin;
    t = target;
    for (string s : words) {
        map<string, int> m;
        if (cmp(b, s))
            dfs(s, words, m, 1);
    }
    return answer == max ? 0 : answer;
}

int main() {
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}