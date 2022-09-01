#include <iostream>

using namespace std;
int cal[1001] = { 0, };
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cal[0] = 1;
	cal[1] = 2;
	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) cout << 2;
	else {

		for (int i = 2; i < n; i++) {
			cal[i] = (cal[i - 2] % 10007 + cal[i - 1] % 10007) % 10007;
		}
		cout << cal[n - 1]%10007;
	}
}