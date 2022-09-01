#include <iostream>
#include <vector>

using namespace std;

int k = 0;
int N;

void star(vector<vector<char>>&v, int x, int y, int n)
{
	if (n == 1)
	{
		v[x][y] = '*';
	}
	else
	{
		star(v,x, y, n / 3);
		star(v,x, y + n / 3, n / 3);
		star(v,x, y + 2 * n / 3, n / 3);
		star(v,x + n / 3, y, n / 3);
		star(v,x + n / 3, y + 2 * n / 3, n / 3);
		star(v,x + 2 * n / 3, y, n / 3);
		star(v,x + 2 * n / 3, y + n / 3, n / 3);
		star(v,x + 2 * n / 3, y + 2 * n / 3, n / 3);
	}
}

int main() {
	cin >> N;

	vector<vector<char>> v(N,vector<char>(N,' '));
	star(v,0,0,N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}