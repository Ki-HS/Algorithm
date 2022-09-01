#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> a;
	vector<int> b;
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		b.push_back(t);
	}
	int sum = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),greater<>());
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
}