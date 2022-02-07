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
	cArr[0] = true;
	cArr[n - 1] = true;
	for (int i = 1; i < n - 1; i++) {
		cArr[n * i / (n - 2) - 1] = true;
		temp.push_back(arr[n * i / (n - 2) - 1]);
	}
	long long l = 1000000000;
	int a = 0;
	for (int i = 1; i <temp.size()-1; i++) {
		if (l > abs(temp[i - 1] - temp[i]))
			l = abs(temp[i - 1] - temp[i]);
		if (l > abs(temp[i + 1] - temp[i]))
			l = abs(temp[i + 1] - temp[i]);
	}
	cout << l;
}