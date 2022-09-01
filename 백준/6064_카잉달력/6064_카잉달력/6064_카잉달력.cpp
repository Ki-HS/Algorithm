#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b) {
	 return (a%b) ? GCD(b, a%b) : b;
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}


int main() {
	int q;
	cin >> q;
	int m, n, x, y;
	while (q--) {
		cin >> m >> n >> x >> y;
		int max = LCM(m, n);
		while (1) {
			if (x > max || (x - 1) % n + 1 == y) break;
			x += m;
		}
		if (x > max)cout << -1 << '\n';
		else cout << x << '\n';
	}
}