#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> N >> M;
	vector<vector<int>> tmt(M, vector<int>(N, 0));
	int t = 0;
	int n;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			tmt[i][j] = n;
		}
	}
	vector<vector<int>> temp = tmt;
	bool status = true;
	while (status) {
		t++;
		status = false;
		for (int i = 0; i < M; i++) {
			auto it2 = find(tmt[i].begin(), tmt[i].end(), 1);
			int a = it2 - tmt[i].begin();
			if (it2 == tmt[i].end()) continue;
			if (a && temp[i][a - 1] == 0) {
				temp[i][a - 1] = 1; status = true;
			}
			if (a != N - 1 && temp[i][a + 1] == 0) { 
				temp[i][a + 1] = 1; 
				status = true; 
			}
			if (i && temp[i - 1][a] == 0) {
				temp[i - 1][a] = 1;
				status = true; 
			}
			if (i != M - 1 && temp[i + 1][a] == 0) {
				temp[i + 1][a] = 1; 
				status = true;
			}
			while (it2 != tmt[i].end()) {
				a = it2 - tmt[i].begin();

				if (a && temp[i][a - 1] == 0) {
					temp[i][a - 1] = 1; status = true;
				}
				if (a != N - 1 && temp[i][a + 1] == 0) {
					temp[i][a + 1] = 1;
					status = true;
				}
				if (i && temp[i - 1][a] == 0) {
					temp[i - 1][a] = 1;
					status = true;
				}
				if (i != M - 1 && temp[i + 1][a] == 0) {
					temp[i + 1][a] = 1;
					status = true;
				}
				it2 = find(it2 + 1, tmt[i].end(), 1);
			}
		}
		tmt = temp;
	}
	bool q = false;
	for (int i = 0; i < M; i++) {
		auto it2 = find(tmt[i].begin(), tmt[i].end(), 0);
		if (it2 != tmt[i].end()) {
			q = true;
			break;
		}
	}
	if (q) cout << -1;
	else cout << t-1;
	
}