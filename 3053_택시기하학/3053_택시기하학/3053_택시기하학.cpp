#include <iostream>

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;

int main() {
	double r;
	cin >> r;
	cout.precision(5);
	cout << fixed;
	cout << r * r * pi << '\n' << r * r * 2;
}