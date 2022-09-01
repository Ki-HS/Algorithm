#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
	return a.first < b.first;
}
bool cmp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
	return a.second.first < b.second.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	int num;
	vector<pair<int, pair<int,int>>>x;

	for (int i = 0; i < n; i++) {
		cin >> num;
		x.push_back(make_pair(num, make_pair(i, 0)));
	}
	sort(x.begin(), x.end(), cmp);
	int order = 1;
	for (int i = 1; i < n; i++) {
		if (x[i].first == x[i - 1].first) {
			x[i].second.second = x[i - 1].second.second;
		}
		else {
			x[i].second.second = order; order++;
		}
	}

	sort(x.begin(), x.end(), cmp2);
	for (int i = 0; i < n; i++) {
		cout << x[i].second.second << " ";
	}
}