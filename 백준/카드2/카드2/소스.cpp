#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	queue<int> a;
	for (int i = 1; i <= n; i++)a.push(i);

	while (a.size() != 1) {
		a.pop();
		a.push(a.front());
		a.pop();
	}
	cout << a.front();
}