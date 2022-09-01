#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (!t) {
			if (q.size()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else q.push(t);
	}
}

