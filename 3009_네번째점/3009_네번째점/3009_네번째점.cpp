#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c, d,e,f;
	cin >> a >> b >> c >> d >> e >> f;

	int x, y;
	if (a == e && e == c)x = a;
	else if (a == e)x = c;
	else if (a == c)x = e;
	else x = a;

	if (b == d && d == f)y = b;
	else if (b == d)y = f;
	else if (b == f)y = d;
	else y = b;

	cout << x << " " << y;
}