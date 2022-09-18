#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> c;
    for (auto i : s)c.push(i);
    stack<char> t;
    while (!c.empty()) {
        if (c.top() == ')') {
            t.push(c.top());
            c.pop();
        }
        else if (!t.empty() && c.top() == '(' && t.top() == ')') {
            t.pop();
            c.pop();
        }
        else break;
    }

    return c.empty() && t.empty() ? true : false;
}