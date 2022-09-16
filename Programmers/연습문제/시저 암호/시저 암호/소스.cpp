#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')continue;
        if (s[i] > 'Z')
            s[i] = (s[i] + n-'a') % 26 + 'a';
        else s[i] = (s[i] + n-'A') % 26 + 'A';
    }
    return s;
}

int main() {
    cout << solution("z", 1);
}