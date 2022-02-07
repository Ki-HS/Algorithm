#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector < bool > calc(vector<int>n, int sum) {
	vector<bool> b(9, false);
	vector<bool> e;
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			sum -= n[i];
			sum -= n[j];
			if (sum == 100) {
				b[i] = true;
				b[j] = true;
				return b;
			}
			sum += n[i];
			sum += n[j];
		}
	}
	return e;
}
int main() {
	vector<int> n;
	int a;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		n.push_back(a);
	}
	sort(n.begin(), n.end());
	int sum = accumulate(n.begin(), n.end(), 0);
	vector<bool> b = calc(n, sum);
	if (!b.size())return 0;
	for (int i = 0; i < 9; i++) {
		if (!b[i]) {
			cout << n[i] << "\n";
		}
	}

}