#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> m1;
    map<char, int> m2;

    for (int i = 0; i < X.size(); i++) {
        m1[X[i]]++;
    }
    for (int i = 0; i < Y.size(); i++) {
        m2[Y[i]]++;
    }
    string s;
    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        if (m2.find(iter->first) != m2.end()) {
            int t = min(m2[iter->first], m1[iter->first]);

            m2[iter->first]-=t;
            m1[iter->first]-=t;
            for(int i = 0; i< t; i++)
                s += iter->first;
            
        }
    }

    sort(s.begin(), s.end(), greater<>());
    bool zero = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            zero = false;
            break;
        }
    }
    if (zero && s.size() > 0)s = "0";

    if (s == "")s = "-1";
    return s;
}

int main() {
    string x = "5525";
    string y = "1255";
    cout << solution(x, y);
}