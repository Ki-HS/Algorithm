#include <iostream>
#include <string>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;
	while (n!="0") {
		int a = 0;
		bool status = true;
		while (a != n.size() / 2) {
			if (n[a] != n[n.size() - a - 1]) {
				status = false;
				break;
			}
			a++;
		}
		if (status) cout << "yes" << "\n";
		else cout << "no" << "\n";
		cin >> n;
	}
}