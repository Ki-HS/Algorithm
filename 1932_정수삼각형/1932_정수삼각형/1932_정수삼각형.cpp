#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;

	vector<vector<int>> v;

	int t;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j <= i; j++) {
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < v[i].size() - 1; j++) {
			v[i - 1][j] += max(v[i][j], v[i][j + 1]);
		}
	}

	cout << v[0][0];

}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   