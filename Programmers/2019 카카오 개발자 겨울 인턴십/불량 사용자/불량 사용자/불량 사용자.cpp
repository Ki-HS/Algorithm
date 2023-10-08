#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> g_user, g_banned;
vector<string> v[9];
int ans = 0;

bool cmp(string s, string c) {
    if (s.size() != c.size()) return false;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] != '*' && s[i] != c[i])return false;
    }
    return true;
}
map< map<string, int>, int> storage;

void dfs(int cur, map<string, int> m) {
    if (cur == g_banned.size()) {
        if (m.size() == cur && !storage[m]) { storage[m]++; ans++; }
        return;
    }

    auto temp = m;
    for (auto e : v[cur]) {
        m[e];
        dfs(cur + 1, m);
        m = temp;
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    g_user = user_id;
    g_banned = banned_id;

    for (int i = 0; i < g_banned.size(); i++) {
        for (auto user : user_id) {
            if (cmp(user, banned_id[i])) v[i].push_back(user);
        }
    }
    map<string, int> m;
    dfs(0, m);

    return ans;
}

int main() {
    solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" },{"*rodo", "*rodo", "******"});
}