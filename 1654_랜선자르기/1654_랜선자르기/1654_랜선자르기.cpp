#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<long long> v,t;

	long long temp;

	while (n--) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),greater<>());
	long long l=1, h=v[0];

	long long answer=1;

	while (l<h) {
		long long c = (h+l) / 2;
		long long sum = 0;
		for (auto i : v) {
			sum += i / c;
		}
		if (sum >= k) {
			if(answer<c)answer = c;
			l = c + 1;
		}
		else if (sum < k) {
			h = c - 1;
		}
	}
	cout << answer;
}