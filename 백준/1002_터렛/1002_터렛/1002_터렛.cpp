#include <iostream>
#include <cmath>
using namespace std;

int t, x1, yy1, x2, y2, l1,l2;
int main() {
	cin >> t;
	while (t--) {
		cin >> x1 >> yy1 >> l1 >> x2 >> y2 >> l2;

		int len= (x1 - x2)*(x1 - x2) + (yy1 - y2)*(yy1 - y2);
		int radd=(l1 + l2)*(l1 + l2);
		int rsub= (l1 - l2)*(l1 - l2);

		if (len==0 && rsub==0) cout << -1 << '\n';
		else if (len == radd || len == rsub)cout << 1 << '\n';
		else if (rsub<len && len<radd)cout << 2 << '\n';
		else cout << 0 << '\n';
		

	}
}