#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> cs;
    char top;
    for (int i = 0; i < s.size(); i++) {
        if (cs.size())top = cs.top();
        else top = NULL;
        if (top == s[i]) {
            cs.pop();
            continue;
        }
        cs.push(s[i]);
    }

    return cs.size() ? 0 : 1;
}