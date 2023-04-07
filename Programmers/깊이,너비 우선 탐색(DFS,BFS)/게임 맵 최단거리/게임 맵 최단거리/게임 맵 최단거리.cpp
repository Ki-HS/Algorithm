#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
	int cnt = 1;
	int size1 = maps.size();
	int size2 = maps[0].size();
	vector<vector<bool>> visit(size1, vector<bool>(size2, false));
	vector<vector<int>> bfs(size1, vector<int>(size2, 0));
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	visit[0][0] = true;
	bfs[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		if (x < size1 - 1)
		{
			if (!visit[x + 1][y] && maps[x + 1][y])
			{
				visit[x + 1][y] = true;
				bfs[x + 1][y] = bfs[x][y] + 1;
				q.push(make_pair(x + 1, y));
			}
		}

		if (y < size2 - 1)
		{
			if (!visit[x][y + 1] && maps[x][y + 1])
			{
				visit[x][y + 1] = true;
				bfs[x][y + 1] = bfs[x][y] + 1;
				q.push(make_pair(x, y + 1));
			}
		}
		if (x > 0)
		{
			if (!visit[x - 1][y] && maps[x - 1][y])
			{
				visit[x - 1][y] = true;
				bfs[x - 1][y] = bfs[x][y] + 1;
				q.push(make_pair(x - 1, y));
			}
		}
		if (y > 0)
		{
			if (!visit[x][y - 1] && maps[x][y - 1])
			{
				visit[x][y - 1] = true;
				bfs[x][y - 1] = bfs[x][y] + 1;
				q.push(make_pair(x, y - 1));
			}
		}


	}

	if (bfs[size1 - 1][size2 - 1] == 0)return -1;
	else return bfs[size1 - 1][size2 - 1];
}