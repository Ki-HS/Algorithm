#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> s;
	int n;
	cin >> n;
	string c;
	int p;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == "push") {
			cin >> p;
			s.push(p);
		}
		else if (c == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			int a = s.front();
			s.pop();
			cout << a << "\n";
		}
		else if (c == "size") {
			cout << s.size() << "\n";
		}
		else if (c == "empty") {
			if (s.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (c == "front") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			int a = s.front();
			cout << a << "\n";
		}
		else if (c == "back") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			int a = s.back();
			cout << a << "\n";
		}
	}
}
