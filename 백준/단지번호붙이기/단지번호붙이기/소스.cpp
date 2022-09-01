#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> h(n, vector<int>(n, 0));
	string row;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < n; j++) {
			h[i][j] = row[j] - 48;
		}
	}

	vector<int> hc;//단지 별 아파트 개수
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int d = 0;
	int t = 0;
	int r = 0, c = 0;
	int tr, tc;

	while (t != n * n) {
		if (h[c][r] && !visited[c][r]) {
			queue<int>q;
			visited[c][r] = true;
			q.push(c * n + r);
			hc.push_back(0);
			while (!q.empty()) {
				hc[d]++;
				int a = q.front();
				tc = a / n;
				tr = a % n;
				
				q.pop();
				if (!tr && !tc) {
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
				}
				else if (!tc && tr == n-1) {
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
				}
				else if (!tc) {
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
				}
				else if (tc == n-1 && !tr) {
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
				}
				else if (tc == n-1 && tr == n-1) {
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
				}
				else if (tc == n-1) {
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
				}
				else if (tr == 0) {
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
				}
				else if (tr == n-1) {
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
				}
				else {
					if (h[tc - 1][tr] && !visited[tc - 1][tr])
					{
						q.push((tc - 1) * n + tr);
						visited[tc - 1][tr] = true;
					}
					if (h[tc + 1][tr] && !visited[tc + 1][tr]) {
						q.push((tc + 1) * n + tr);
						visited[tc + 1][tr] = true;
					}
					if (h[tc][tr - 1] && !visited[tc][tr - 1]) {
						q.push(tc * n + tr - 1);
						visited[tc][tr - 1] = true;
					}
					if (h[tc][tr + 1] && !visited[tc][tr + 1])
					{
						q.push(tc * n + tr + 1);
						visited[tc][tr + 1] = true;
					}
				}
			}
			d++;
		}

		t++;
		c++;
		if (c == n) {
			c = 0;
			r++;
		}
		tr = r;
		tc = c;
	}
	cout << hc.size() << "\n";
	sort(hc.begin(), hc.end());
	for (int i = 0; i < hc.size(); i++) {
		cout << hc[i] << "\n";
	}
}