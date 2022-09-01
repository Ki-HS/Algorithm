#include <iostream>
#include <vector>

using namespace std;
int n, m;

bool visit[9] = { false, };
int arr[9] = { 0, };

void dfs(int num, int b) {
	arr[b] = num;
	if (b == m - 1) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	visit[num] = true;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i, b + 1);
		}
	}
	visit[num] = false;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
	}

}