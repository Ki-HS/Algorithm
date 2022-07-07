#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
	int n, m;

bool visit[9] = { false, };
int arr[9] = { 0, };
vector<vector<int>> v;

void solution(int x, int y) {
	arr[y] = x;
	if (y == m - 1) {
		
		vector<int>pq;
		for (int i = 0; i < m; i++) {
			pq.push_back(arr[i]);
		}
		sort(pq.begin(), pq.end());
		auto iter = find(v.begin(), v.end(), pq);
		if (iter!= v.end())return;
		
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		v.push_back(pq);
		return;
	}
	visit[x] = true;
	
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			solution(i, y + 1);
		}
	}
	visit[x] = false;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		solution(i, 0);
	}
}