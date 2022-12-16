#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        cout << m[s[i]] << endl;
        if(m[s[i]]==-1)answer.push_back(i);
        else if (m[s[i]])answer.push_back(i - m[s[i]]);
        else answer.push_back(-1);
        if(i==0)m[s[i]] = -1;
        else m[s[i]] = i;
    }
    cout << endl << endl;
    return answer;
}

int main() {
    vector<int> v = solution("rhrnakajrrhtlvek");
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}