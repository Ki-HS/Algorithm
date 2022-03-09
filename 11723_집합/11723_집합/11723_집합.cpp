#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string cmd;
	int arg;
	map<int, int> s;
	map<int, int> mt;
	map<int, int> all;
	for (int i = 0; i < 20; i++)
		all.insert(make_pair(i + 1, i + 1));
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> arg;
			if (s.find(arg) == s.end()) {
				s.insert(make_pair(arg, arg));
			}
		}
		else if (cmd == "check") {
			cin >> arg;
			if (s.find(arg) == s.end()) cout << 0 << "\n";
			else cout << 1 << "\n";

		}
		else if (cmd == "remove") {
			cin >> arg;
			if (s.find(arg) != s.end()) {
				s.erase(arg);

			}
		}
		else if (cmd == "toggle") {
			cin >> arg;

			if (s.find(arg) != s.end()) {
				s.erase(arg);
			}
			else
				s.insert(make_pair(arg, arg));
		}
		else if (cmd == "all") {
			s = all;
		}
		else {//command is "empty"
			s = mt;
		}
	}
}