#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	string n, m;
	cin >> n >> m;
	stack<char> qu; 
	stack<char> stk;
	bool status = false;
	for (int i = 0; i < n.size(); i++) {
		stk.push(n[i]);
		status = false;
		if (stk.top() == m.back()&&stk.size()>=m.size()) {
			for (int j = m.size()-1; j >= 0; j--) {
				if (stk.top() == m[j]) {
					if (j == 0) status = true;
					qu.push(stk.top());
					stk.pop();
				}
				else break;
			}
				if (status) {
					while (!qu.empty())qu.pop();
				}
				else {
					while (!qu.empty()) {
						stk.push(qu.top());
						qu.pop();
					}
				}
		}
	}

	if (stk.size()) {
		stack<char> sk;
		while (!stk.empty()) {
			sk.push(stk.top());
			stk.pop();
		}
		while (!sk.empty()) {
			cout << sk.top();
			sk.pop();
		}
	}
	else cout << "FRULA";;

	

}
