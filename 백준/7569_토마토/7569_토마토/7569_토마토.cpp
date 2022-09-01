#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N, H;
	cin >> N >>M>> H;

	vector<vector<vector<int>>> tmt(H, vector <vector<int>>(M, vector<int>(N, 0)));


	int a;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> a;
				tmt[i][j][k] = a;
			}
		}
	}

	queue<pair<int, pair<int, int>>> q;
	int h = 0, r = 0, c = 0;
	for (int i = 0; i < H*M * N; i++) {
		if (c == N) {
			r++; c = 0;
		}
		if (r == M) {
			h++; r = 0;
		}
		if (tmt[h][r][c] == 1) {
			q.push(make_pair(h, make_pair(r, c)));
		}

		c++;
	}
	int t = -1;
	int z = q.size();
	while (!q.empty()) {
		h = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		if (h != 0 && !tmt[h - 1][r][c]) {
			q.push(make_pair(h - 1, make_pair(r, c)));
			tmt[h - 1][r][c] = 1;
		}
		if (h != H - 1 && !tmt[h + 1][r][c]) {
			q.push(make_pair(h + 1, make_pair(r, c)));
			tmt[h + 1][r][c] = 1;
		}
		if (r != 0 && !tmt[h][r - 1][c]) {
			q.push(make_pair(h, make_pair(r - 1, c)));
			tmt[h][r - 1][c] = 1;
		}
		if (r != M - 1 && !tmt[h][r + 1][c]) {
			q.push(make_pair(h, make_pair(r + 1, c)));
			tmt[h][r + 1][c] = 1;
		}
		if (c != 0 && !tmt[h][r][c - 1]) {
			q.push(make_pair(h, make_pair(r, c - 1)));
			tmt[h][r][c - 1] = 1;
		}
		if (c != N - 1 && !tmt[h][r][c + 1]) {
			q.push(make_pair(h, make_pair(r, c + 1)));
			tmt[h][r][c + 1] = 1;
		}

		z--;
		if (!z) {
			z = q.size();
			t++;
		}
	}
	bool w = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {

			auto it2 = find(tmt[i][j].begin(), tmt[i][j].end(), 0);
			if (it2 != tmt[i][j].end()) {
				w = true;
				break;
			}
		}
	}
	if (w) cout << -1;
	else cout << t;
}
