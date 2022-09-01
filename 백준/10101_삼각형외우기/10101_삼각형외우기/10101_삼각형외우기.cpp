#include <iostream>
#include <map>
using namespace std;

int main() {
	int t, sum=0;
	map<int, int> m;
	for (int i = 0; i < 3; i++) {
		cin >> t;
		sum += t;
		m[t]++;
	}
	if (sum != 180) cout << "Error";
	else if (m.size() == 3) cout << "Scalene";
	else if (m.size() == 2)cout << "Isosceles";
	else cout << "Equilateral";
}