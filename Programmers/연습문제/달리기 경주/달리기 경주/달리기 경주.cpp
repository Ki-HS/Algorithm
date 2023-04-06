#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<string, int> m;

    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }

    for (string s : callings) {
        int idx = m[s];

        m[players[idx]]--;
        m[players[idx - 1]]++;

        players[idx] = players[idx - 1];
        players[idx - 1] = s;
        
    }

    return players;
}

int main() {
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });
}