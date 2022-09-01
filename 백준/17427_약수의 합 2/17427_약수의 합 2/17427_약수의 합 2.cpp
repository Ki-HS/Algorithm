#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	long long t3 = 0;
	for (int i = 1; i <= t; i++) {
		t3 += i * (t / i);
	}
	cout << t3;
}