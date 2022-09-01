#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<int> dx = { 0,0,1,-1 }, dy = { 1,-1,0,0 };
vector<vector<char>> a;
int R, C;
int ans = 0;
int cur = 0;
vector<bool> vis(26);
void dfs(int x, int y) {
	int c = a[x][y] - 'A';
	vis[c] = 1;
	cur += 1;
	ans = max(ans, cur);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (vis[a[nx][ny] - 'A']) continue;
			dfs(nx, ny);
		}
	}
	cur -= 1;
	vis[c] = 0;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	cin >> R >> C;
	a = vector<vector<char>>(R,vector<char>(C,'\0'));
	char l;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> l;
			a[i][j]=l;
		}
	}

	dfs(0, 0);
	cout << ans;
}