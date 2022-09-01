#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;

	cin >> a >> b >> c;
	int t;
	while (a || b || c) {
		t = 0;
		if (a > t)t = a;
		if (b > t)t = b;
		if (c > t)t = c;
		if (a==t)
		{
			if (pow(c, 2) + pow(b, 2) == pow(a, 2))cout << "right" << "\n";
			else cout << "wrong" << "\n";
		}
		else if(t==b)
		{
			if (pow(a, 2) + pow(c, 2) == pow(b, 2))cout << "right" << "\n";
			else cout << "wrong" << "\n";
		}
		else if (t == c) {
			if (pow(a, 2) + pow(b, 2) == pow(c, 2))cout << "right" << "\n";
			else cout << "wrong" << "\n";
		}
		else
			cout << "wrong" << "\n";
		
		cin >> a >> b >> c;
	}

}

