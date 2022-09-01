#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double d, h, w;

	cin >> d >> h >> w;

	double x, y;
	d *= d;
	x = pow(h, 2);
	y = pow(w, 2);
	d /= x + y;
	d = sqrt(d);
	x = h * d;
	y = w * d;

	cout << floor(x) << " " << floor(y);
}