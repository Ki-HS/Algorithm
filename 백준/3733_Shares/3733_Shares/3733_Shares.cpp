#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, s;

	while (cin >> n >> s) {
		cout << s / (n + 1) << '\n';
	}
	
}