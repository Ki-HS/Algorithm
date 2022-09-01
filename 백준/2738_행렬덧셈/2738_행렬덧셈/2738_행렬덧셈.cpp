#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v1(n,vector<int>(m,0));
	vector<vector<int>> v2(n,vector<int>(m,0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v1[i][j] + v2[i][j] << " ";
		}
		cout << "\n";
	}
	
}