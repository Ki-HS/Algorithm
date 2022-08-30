#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 10000000
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, INF));
	int a, b;
	int t = 0;
	while (m--) {
		cin >> a >> b;
		if(t<n)v[t][t] = 0;
		t++;
		v[a - 1][b - 1] = 1;
		v[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];
			}
		}
	}


	int minIdx = 0, minTmp = INF;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (v[i][j] < n)sum += v[i][j];
		}
		if (sum < minTmp&&sum) {
			minTmp = sum;
			minIdx = i + 1;
		}
	}



	cout << minIdx;
}