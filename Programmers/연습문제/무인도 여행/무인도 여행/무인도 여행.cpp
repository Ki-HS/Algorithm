#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;

int travel(int a, int b, vector<string>& m) {
	queue<pair<int, int>> q;

	q.push({ a,b });
	int cnt = 0;
	cnt += m[a][b] - '0';
	m[a][b] = 'X';
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		int x = tmp.first;
		int y = tmp.second;
		q.pop();
		if (x > 0 && m[x - 1][y] != 'X') {
			q.push({ x - 1,y });       
			cnt += m[x - 1][y] - '0';
			m[x - 1][y] = 'X';
		}

		if (y < w - 1 && m[x][y + 1] != 'X') {
			q.push({ x ,y + 1 });
			cnt += m[x][y + 1] - '0';
			m[x][y + 1] = 'X';
		}

		if (y > 0 && m[x][y - 1] != 'X') {
			q.push({ x ,y - 1 }); 
			cnt += m[x][y - 1] - '0';
			m[x][y - 1] = 'X';
		}

		if (x < h - 1 && m[x + 1][y] != 'X') {
			q.push({ x + 1,y }); 
			cnt += m[x + 1][y] - '0';
			m[x + 1][y] = 'X';
		}
	}

	return cnt;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	w = maps[0].size();
	h = maps.size();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (maps[i][j] != 'X') answer.emplace_back(travel(i, j, maps));
		}
	}
	if (answer.size())
	{
		sort(answer.begin(), answer.end());
		return answer;
	}
	else return { -1 };
}

int main() {
	solution({ "X591X","X1X5X","X231X", "1XXX1" });
}