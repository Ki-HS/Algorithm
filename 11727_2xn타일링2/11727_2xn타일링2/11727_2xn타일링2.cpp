#include <iostream>

using namespace std;

int cal[1001] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;//1,3,5,11
	cal[0] = 1;
	cal[1] = 3;
	if (n == 1) cout << 1;
	else if (n == 2)cout << 3;
	else {
		for (int i = 2; i < n; i++) {
			cal[i] = (2*cal[i - 2] % 10007 + cal[i - 1] % 10007) % 10007;
		}
		cout << cal[n - 1] % 10007;
	}

}