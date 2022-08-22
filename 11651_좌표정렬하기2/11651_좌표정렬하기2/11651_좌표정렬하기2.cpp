#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorting1(pair<int, int> a, pair<int, int>b) {
	return a.second < b.second;
}

bool sorting2(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n;
	vector<pair<int, int>> v;

	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), sorting1);
	stable_sort(v.begin(), v.end(), sorting2);

	for (auto i : v) {
		cout << i.first << " " << i.second << "\n";
	}

}