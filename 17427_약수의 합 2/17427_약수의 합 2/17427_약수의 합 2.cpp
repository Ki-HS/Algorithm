#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int t = 1;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)t += i;
	}
	if(n!=1)t += n;
	int t3 = 1;
	for (int j = 2; j < t; j++) {
		int t2 = 1;
		for (int i = 2; i <= j / 2; i++) {
			if (j % i == 0)t2 += i;
		}
		if (j != 1)t2 += j;
		t3 += t2;
	}
	cout << t3;
}