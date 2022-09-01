#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> board(102, 0);
	vector<int> cur(102);
	for (int i = 1; i <= 100; i++)cur[i] = i;

	int x, y;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		cur[x] = y;
	}

	board[1] = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			y = x + i;
			if (y > 100)break;
			y = cur[y];
			if (!board[y]) {
				board[y] = board[x] + 1;
				q.push(y);
			}

		}
	}
	cout << board[100];
} 