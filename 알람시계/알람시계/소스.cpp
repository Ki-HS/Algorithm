#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	m -= 45;
	if (m < 0) {
		n--;
		m += 60;
	}
	if (n < 0) n += 24;
	cout << n << ' ' << m;
}