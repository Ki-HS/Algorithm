#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool sorting(pair<pair<int, string>, int>a, pair<pair<int, string>, int> b) {
	return a.first.first < b.first.first;
}
bool st_sorting(pair<pair<int, string>, int>a, pair<pair<int, string>, int> b) {
	if (a.first.first == b.first.first) return a.second < b.second;
	else return false;
}

int main() {
	cin.tie();
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<pair<int, string>,int>> mem;

	int a;
	string b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mem.push_back(make_pair(make_pair(a, b),i));
	}
	sort(mem.begin(), mem.end(), sorting);
	stable_sort(mem.begin(), mem.end(), st_sorting);
	for (int i = 0; i < n; i++) {
		cout << mem[i].first.first << " " << mem[i].first.second << "\n";
	}
}