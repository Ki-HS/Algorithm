#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	long long n, c;
	vector<long long> arr;
	cin >> n >> c;
	vector<bool> cArr(n, false);
	vector < long long  > temp;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	int left = 1;
	int right = arr.back();
	int mid = (left + right) / 2;

	int cnt; 
	int ans=0;
	int a, b, q;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1;

		a = arr.front();
		for (auto i = 1; i < arr.size(); i++) {
			b = arr.at(i);
			q = b - a;
			if (q >= mid) {
				a = b;
				cnt++;
			}
		}

		if (cnt < c)right = mid - 1;
		else {
			ans = mid;
			left = mid + 1;
		}
	}

	cout << ans;
}