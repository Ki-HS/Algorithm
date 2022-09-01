#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n;
	int t;
	cin >> t;
	while (t--) {
		cin >> k >> n;
		vector<vector<int>> v(k+1, vector<int>(n, 0));
		int fsum;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				if (i != 0) {
					for (int a = 0; a <= j; a++)
						v[i][j] += v[i - 1][a];
				}
				else {
					v[i][j] = j+1;
				}
			}
		}
		cout << v[k][n - 1] << "\n";
	}
}