#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = s.substr(0, n);

	unsigned long long ull=0, thirtyone=1;
	for (int i = 0; i < s.size(); i++) {
		if (i) {
			thirtyone *= 31;
			thirtyone %= 1234567891;
		}
		ull += (s[i] - 'a'+1) *thirtyone;
		ull %= 1234567891;
	}

	cout << ull;
}