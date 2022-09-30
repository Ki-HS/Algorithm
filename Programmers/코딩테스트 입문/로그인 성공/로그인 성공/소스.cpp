#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    map<string, string> m;
    for (auto i : db) {
        m[i[0]] = i[1];
    }

    if (m[id_pw[0]]!="") {
        if (m[id_pw[0]]==id_pw[1]) return "login";
        else return "wrong pw";
    }
    else return "fail";
}

int main() {
    vector<vector<string>> s = { {"a","a"}, {"b","a"}, {"c","a"} };
    vector<string> v = { "a","b" };
    cout<<solution(v, s);
}