#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;

	long long t;

	vector<long long> tree;
	for (long long i = 0; i < n; i++) {
		cin >> t;
		tree.push_back(t);
	}
	sort(tree.begin(), tree.end());
	long long left = 0;
	long long right = tree.back();
	long long mid = (left + right) / 2;

	long long temp;
	long long ans=0;
	while (left <= right) {
		temp = 0;
		mid = (left + right) / 2;

		for (long long i=0; i < tree.size();i++) {
			if (tree[i] - mid < 0) continue;
			temp += tree[i] - mid;
		}
		if (temp < m) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
			if (mid > ans) {
				ans = mid;
			}

		}
	}

	cout << ans;
}