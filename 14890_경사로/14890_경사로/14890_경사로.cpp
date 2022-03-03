#include <iostream>
#include <string.h>

using namespace std;

int map[100][100] = { 0 };
int res = 0;
int sloped[100] = { 0 };
int N, L;

void simulation()
{
	for (int i = 0; i < N; i++)
	{
		// Init
		memset(sloped, 0, sizeof(int) * 100);

		// Reverse
		int suc = 1;
		int last = map[i][N - 1];
		int j;
		for (j = N - 2; j >= 0; j--)
		{
			if (map[i][j] == last)
			{
				suc++;
			}
			else if (map[i][j] - last == 1)
			{
				if (suc >= L)
				{
					for (int k = 1; k <= L; k++)
					{
						sloped[j + k] = -1;
					}
					suc = 1;
					last = map[i][j];
				}
				else
				{
					break;
				}
			}
			else if (last - map[i][j] == 1)
			{
				suc = 1;
				last = map[i][j];
			}
			else
			{
				break;
			}
		}

		if (j >= 0) continue;

		// Normal
		suc = 1;
		last = map[i][0];
		for (j = 1; j < N; j++)
		{
			if (sloped[j] == -1)
			{
				suc = 1;
				last = map[i][j + L];
				j += L;
			}
			else if (map[i][j] == last)
			{
				suc++;
			}
			else if (map[i][j] - last == 1)
			{
				if (suc >= L)
				{
					for (int k = 1; k <= L; k++)
					{
						sloped[j - k] = 1;
					}
					suc = 1;
					last = map[i][j];
				}
				else
				{
					break;
				}
			}
			else if (last - map[i][j] == 1)
			{
				suc = 1;
				last = map[i][j];
			}
			else
			{
				break;
			}
		}

		if (j < N) continue;

		// Test
		int height = map[i][0];
		int x = 0;
		while (true)
		{
			if (x >= N)
			{
				if (height == map[i][N - 1])
				{
					res++;
				}
				break;
			}

			if (sloped[x] == 0)
			{
				x++;
			}
			else if (sloped[x] == 1)
			{
				x += L;
				height++;
			}
			else if (sloped[x] == -1)
			{
				x += L;
				height--;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	simulation();

	int copied[100][100] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copied[i][j] = map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = copied[j][i];

	simulation();

	cout << res << '\n';

	return 0;
}