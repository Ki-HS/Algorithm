#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	getline (cin,s);
	while (s != ".") {
		stack<char> stk;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.')break;
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') stk.push(s[i]);
			if (s[i] == ')') {
				if (stk.empty()) {
					stk.push('0');
					break;
				}
				if (stk.top() == '(')stk.pop();
				else break;
			}
			if (s[i] == '}') {
				if (stk.empty()) {
					stk.push('0');
					break;
				}
				if (stk.top() == '{')stk.pop();
				else break;
			}
			if (s[i] == ']') {
				if (stk.empty()) {
					stk.push('0');
					break;
				}
				if (stk.top() == '[')stk.pop();
				else break;
			}
			
		}
		if (stk.empty())cout << "yes\n";
		else cout << "no\n";
		getline(cin, s);
	}
}