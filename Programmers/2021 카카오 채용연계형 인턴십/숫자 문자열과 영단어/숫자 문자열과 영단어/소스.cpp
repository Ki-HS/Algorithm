#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')answer += s[i];
        else temp += s[i];

        if (temp == "zero") { answer += "0"; temp = ""; }
        else if (temp == "one") { answer += '1'; temp = ""; }
        else if (temp == "two") { answer += '2'; temp = ""; }
        else if (temp == "three") { answer += '3'; temp = ""; }
        else if (temp == "four") { answer += "4"; temp = ""; }
        else if (temp == "five") { answer += '5'; temp = ""; }
        else if (temp == "six") { answer += '6'; temp = ""; }
        else if (temp == "seven") { answer += '7'; temp = ""; }
        else if (temp == "eight") { answer += '8'; temp = ""; }
        else if (temp == "nine") { answer += '9'; temp = ""; }
    }
    return stoi(answer);
}