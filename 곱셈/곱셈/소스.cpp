#include <iostream>
#include <cmath>
using namespace std;

long long pow(long long a, long long b, long long c) {
	long long result = 1;
	while (b) {
		if (b & 1) result = result * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return result;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	long long result=pow(a, b, c);
	
	cout << result;
}