#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int result;
	if (x > 0 && y > 0) result = 1;
	else if (x > 0 && y < 0) result = 4;
	else if (x < 0 && y>0) result = 2;
	else result = 3;

	cout << result;
}