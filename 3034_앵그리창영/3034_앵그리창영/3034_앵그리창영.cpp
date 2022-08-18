#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;

	int t;
	while (n--) {
		cin >> t;
		if(t<=w||t<=h) cout << "DA\n";
		else if (sqrt(t * t - w * w) <= h) cout << "DA\n";
		else cout << "NE\n";
	}
}