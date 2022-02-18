#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> deque;
	string cmd;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push_back") {
			cin >> a;
			deque.push_back(a);
		}
		else if (cmd == "push_front") {
			cin >> a;
			deque.insert(deque.begin(), a);
		}
		else if (cmd == "pop_front") {
			if (!deque.size()) {
				cout << -1 << "\n";
				continue;
			}
			cout << deque[0]<<"\n";
			deque.erase(deque.begin());
		}
		else if (cmd == "pop_back") {
			if (!deque.size()) {
				cout << -1 << "\n";
				continue;
			}
			cout << deque[deque.size()-1] << "\n";
			deque.erase(deque.end() - 1);
		}
		else if (cmd == "size") {
			cout << deque.size() << "\n";
		}
		else if (cmd == "empty") {
			if (!deque.size()) {
				cout << 1 << "\n";
				continue;
			}
			else cout << 0 << "\n";
		}
		else if (cmd == "front") {
			if (!deque.size()) {
				cout << -1 << "\n";
				continue;
			}
			cout << deque[0] << "\n";
		}
		else if (cmd == "back") {
			if (!deque.size()) {
				cout << -1 << "\n";
				continue;
			}
			cout << deque[deque.size() - 1] << "\n";
		}
	}
}