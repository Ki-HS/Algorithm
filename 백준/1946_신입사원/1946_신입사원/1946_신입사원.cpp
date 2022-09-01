#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int p;
	int a, b;
	int f, s;
	vector<pair<int, int>> h;
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++) {
		cin >> p;
		cnt = 0;
		h = temp;
		f = s = 100000;

		for (int j = 0; j < p; j++) {
			cin >> a >> b;
			h.push_back(make_pair(a, b));
		}
		sort(h.begin(), h.end());
		int t = h[0].second;
		for (int j = 0; j < p; j++) {
			if (t >= h[j].second) {
				cnt++;
				t = h[j].second;
			}
		}
		cout << cnt << "\n";
	}
}