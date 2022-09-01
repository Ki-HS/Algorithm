#include <iostream>
using namespace std;

int gcd1(int a, int b) {
	if (!b)return a;
	else return gcd1(b, a % b);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int t;
	long long max = 0, gcd = 1;
	long long min = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (max < t) max = t;
		if (min > t)min = t;
		gcd = gcd*t/gcd1(gcd, t);
	}

	
	if (max == gcd)gcd *= min;
	cout << gcd;

	
}