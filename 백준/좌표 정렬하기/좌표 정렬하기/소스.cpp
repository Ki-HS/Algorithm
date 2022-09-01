#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort1(pair<int, int> a, pair<int, int>b) {
	return a.first < b.first;
}

bool sort2(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return 0;
}

int main() {
	int n;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	vector < pair<int, int>> xy;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		xy.push_back(make_pair(a, b));
	}

	sort(xy.begin(), xy.end(), sort1);
	stable_sort(xy.begin(), xy.end(), sort2);
	for (int i = 0; i < n; i++) {
		cout << xy[i].first << " " << xy[i].second << "\n";
	}
}