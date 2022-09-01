#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int s = 1000;
	if (s > x)
		s = x;
	if (s > y)
		s = y;
	if (s > abs(x - w))
		s = abs(x - w);
	if (s > abs(y - h))
		s = abs(y - h);
	cout << s;
	return 0;
}