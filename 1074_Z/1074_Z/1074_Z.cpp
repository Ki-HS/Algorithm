#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;
bool s = false;
void cal(int la, int ra, int lb, int rb) {
	if (ra < la || rb < lb) return;
	if (ra - la == 1 && rb - lb == 1) {
		if (la == r && rb == c) cnt += 1;
		else if (ra == r && lb == c) cnt += 2;
		else if (ra == r && rb == c)cnt += 3;
		return;
	}
	else if (r <= (la + ra) / 2  && c <= (lb + rb) / 2) {
		cal(la, (la + ra) / 2, lb, (lb + rb) / 2);
	}
	else if (r > (la + ra) / 2 && c > (lb + rb) / 2) {
		cnt += pow((ra - la + 1) / 2, 2) * 3;
		cal((la + ra) / 2 + 1, ra, (lb + rb) / 2 + 1, rb);
	}
	else if (r <= (la + ra) / 2 && c > (lb + rb) / 2) {
		cnt += pow((ra - la + 1) / 2, 2) ;
		cal(la, (la + ra) / 2, (lb + rb) / 2 + 1, rb);
	}
	else if (r > (la + ra) / 2 && c <= (lb + rb) / 2) {
		cnt += pow((ra - la + 1) / 2, 2)*2;
		cal((la + ra) / 2 + 1, ra, lb, (lb + rb) / 2);
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> r >> c;
	r++;
	c++;
	cal(1, pow(2, n), 1, pow(2, n));
	cout << cnt;
	return 0;
}