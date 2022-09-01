#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	int n,m;
	cin >> n>>m;
	int t;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i == 0) {
			v[i] = t;
			continue;
		}
		v[i] = t+v[i - 1];
	}

	int a, b;

	while (m--) {
		cin >> a >> b;
		int sum = v[b - 1];
		if (a > 1)sum -= v[a - 2];
		cout << sum << '\n';
	}
}