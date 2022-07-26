#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	
	if ((xb - xa) * (yc - yb) == (yb - ya) * (xc - xb)) { cout << -1; return 0; }

	double len1, len2, len3;
	len1 =  2 *sqrt(pow(ya - yb, 2) + pow(xa - xb, 2));
	len2 =  2 *sqrt(pow(ya - yc, 2) + pow(xa - xc, 2));
	len3 =  2 *sqrt(pow(yc - yb, 2) + pow(xc - xb, 2));

	double minC, maxC;
	minC = min(len1 + len2, min(len1 + len3, len2 + len3));
	maxC = max(len1 + len2, max(len1 + len3, len2 + len3));
	cout.precision(16);
	cout<<fixed;
	cout << (maxC - minC);
}