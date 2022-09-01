#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	int time = 1;
	c -= a;
	time += ceil( c / (a - b));
	cout << time;
}