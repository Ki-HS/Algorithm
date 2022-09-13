#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<long long>v(101, 0);
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i <= 100; i++) {
		v[i] = v[i - 2] + v[i - 3];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << v[n] << endl;
	}
}