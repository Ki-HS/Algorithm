#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    bool st = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { st = false; continue; }
        if (st == false && s[i] >= 'a')s[i] -= 32;
        else if (st == true && s[i] >= 'A' && s[i] <= 'Z')s[i] += 32;
        st = true;

    }

    return s;
}