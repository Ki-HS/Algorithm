#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n;
	int k;
	cin >> n;
	cin >> k;
	int* order = new int[n + 1];
	memset(order, 0, n);
	bool* kill = new bool[n + 1];
	memset(kill, false, n);
	int i = 1;
	int a = 0;
	int c = 0;
	while (i < n * k + 1) {
		if (i % k == 0 && kill[a] == false) {
			kill[a] = true;
			order[c] = a + 1;
			c++;
			a++;
			i++;
			if (a == n)a = 0;
			continue;
		}
		if (kill[a] == false) i++;
		a++;
		if (a == n)a = 0;
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << order[i];
		if (i != n - 1)cout << ", ";
	}
	cout << ">";
}