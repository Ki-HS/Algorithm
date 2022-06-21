#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> odd;
	vector<int> even;
	for (int i = 1; i <= n; i++) {
		if (i % 2)odd.push_back(i);
		else even.push_back(i);
	}
	if (n % 2==0) {
		int t = odd[0];
		odd[0] = odd[1];
		odd[1] = t;

		odd.push_back(5);
		odd.erase(odd.begin() + 2);
		even.insert(even.end(), odd.begin(), odd.end());
		for (int i = 0; i < even.size(); i++) {
			cout << even[i] << '\n';
		}
	}
	else if (n % 3 == 0) {
		even.push_back(even[0]);
		even.erase(even.begin());

		odd.push_back(odd[0]);
		odd.erase(odd.begin());
		odd.push_back(odd[0]);
		odd.erase(odd.begin());
		even.insert(even.end(), odd.begin(), odd.end());
		
		for (int i = 0; i < even.size(); i++) {
			cout << even[i] << '\n';
		}
	}
	else {
		odd.insert(odd.end(), even.begin(), even.end());
		for (int i = 0; i < odd.size(); i++) {
			cout << odd[i] << '\n';
		}
	}
}