#include <iostream>
#include <vector>
using namespace std;
int n;
int blue = 0, white = 0;
vector<vector<int>> v;
vector<vector<int>> v2;

int minimum(vector<vector<int>> w, int a, int b, int t) {
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < t; i++) {
		if (v[a][b + i] == v[a][b]) x++;
		else break;
	}
	for (int i = 0; i < t; i++) {
		if (v[a + i][b] == v[a][b]) y++;
		else break;
	}
	for (int i = 0; i < t; i++) {
		if (v[a + i][b + i] == v[a][b]) z++;
		else break;
	}

	if (x ==t&& y ==t&& z == t)
		return t;
	else return 0;
}

void color(int a, int b, int a1, int b1, int t) {
	v2 = v;
	if (v[a][b] == 2||a>a1||b>b1) return;
	if (minimum(v, a, b,t) == t) {
		if (v[a][b] == 0) {
			for (int i = a; i < a1; i++) {
				for (int j = b; j < b1; j++) {
					if (v[i][j] == 1) {
						v = v2;
						color(a, b, (a + a1) / 2, (b + b1) / 2, t / 2);
						//cout << white << " " << blue<< "\n";
						color(a, (b + b1) / 2, (a + a1) / 2, b1, t / 2);
						//cout << white << " " << blue<< "\n";
						color((a + a1) / 2, b, a1, (b + b1) / 2, t / 2);
						//cout << white << " " << blue<< "\n";
						color((a + a1) / 2, (b + b1) / 2, a1, b1, t / 2);
						//cout << white << " " << blue<< "\n";
						return;
					}
					v[i][j] = 2;
				}
			}
			white++;
			return;
		}
		else if (v[a][b] == 1) {
			for (int i = a; i < a1; i++) {
				for (int j = b; j <b1; j++) {
					if (v[i][j] == 0) {
						v = v2;
						color(a, b, (a + a1) / 2, (b + b1) / 2, t / 2);
						//cout << white << " " << blue<< "\n";
						color(a, (b + b1) / 2, (a + a1) / 2, b1, t / 2);
						//cout << white << " " << blue<< "\n";
						color((a + a1) / 2, b, a1, (b + b1) / 2, t / 2);
						//cout << white << " " << blue<< "\n";
						color((a + a1) / 2, (b + b1) / 2, a1, b1, t / 2);
						//cout << white << " " << blue<< "\n";
						return;
					}
					v[i][j] = 2;
				}
			}
			blue++;
			return;
		}
	}
	color(a, b, (a+a1)/2, (b+b1)/2, t / 2);
	//cout << white << " " << blue<< "\n";
	color(a, (b + b1) / 2,(a+a1)/2, b1, t / 2);
	//cout << white << " " << blue<< "\n";
	color((a + a1) / 2, b, a1,(b+b1)/2 ,t / 2);
	//cout << white << " " << blue<< "\n";
	color((a + a1) / 2, (b + b1) / 2, a1, b1, t / 2);
	//cout << white << " " << blue<< "\n";
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	v2 = v;
	int num;
	if (!n) return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			v[i][j] = num;
		}
	}
	color(0, 0, n, n, n);

	cout << white << "\n" << blue;

}