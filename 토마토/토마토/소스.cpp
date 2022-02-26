#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

	queue<pair<int, int>> q;
	int r = 0, c = 0;
	for (int i = 0; i < M * N; i++) {
		if (c == N) {
			r++; c = 0;
		}
		if (tmt[r][c] == 1) {
			q.push(make_pair(r, c));
		}
		

		c++;
	}
	int z = q.size();
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a != 0 && !tmt[a - 1][b]) {
			q.push(make_pair(a - 1, b));
			tmt[a - 1][b] = 1;
		}
		if (a != M - 1 && !tmt[a + 1][b]) {
			q.push(make_pair(a + 1, b));
			tmt[a + 1][b] = 1;
		}
		if (b != 0 && !tmt[a][b - 1]) {
			q.push(make_pair(a, b - 1));
			tmt[a][b - 1] = 1;
		}
		if (b != N - 1 && !tmt[a][b + 1]) {
			q.push(make_pair(a, b + 1));
			tmt[a][b + 1] = 1;
		}
		z--;
		if (!z) {
			z = q.size();
			t++;
		}
	}

	bool w = false;
	for (int i = 0; i < M; i++) {
		auto it2 = find(tmt[i].begin(), tmt[i].end(), 0);
		if (it2 != tmt[i].end()) {
			w = true;
			break;
		}
	}
	if (w) cout << -1;
	else cout << t - 1;
}