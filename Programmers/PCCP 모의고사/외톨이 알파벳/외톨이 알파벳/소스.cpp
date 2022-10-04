#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int >m;
    for (auto i : s)m[i]++;
    for (auto i : m) {
        bool status = false;
        for (int j = 0; j < s.size(); j++) {

            if (status && s[j] == i.first && s[j - 1] != i.first) {
                answer += s[j];
                break;
            }
            else if (s[j] == i.first) status = true;
        }
    }
    if (answer == "")return "N";
    sort(s.begin(), s.end());
    return answer;
}