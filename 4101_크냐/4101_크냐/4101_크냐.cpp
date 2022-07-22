#include <iostream>

using namespace std;

int main() {
	int n, m;

	while (true) {
		cin >> n >> m;
		if (!n && !m)break;
		if (n > m)cout << "Yes\n";
		else cout << "No\n";
	}
}