#include <iostream>

using namespace std;

int main() {
	cin.tie();
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int h, w, m;
	for (int i = 0; i < n; i++) {
		cin >> h >> w >> m;
		int a = m / h;
		int b = m % h;
		if ((m!=h&&b)||h>m)  a++;
		if (!b && a)  b = h;

		cout << b * 100 + a<< "\n";
	}
}