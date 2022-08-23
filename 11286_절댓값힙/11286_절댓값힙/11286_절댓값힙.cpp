#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int a, int b){
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	int n;
	cin >> n;
	int t;
	priority_queue<int, vector<int>, compare>pq;
	while (n--) {
		cin >> t;
		if (t) {
			pq.push(t);
		}
		else {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top()<<'\n';
			pq.pop();
		}
	}
}