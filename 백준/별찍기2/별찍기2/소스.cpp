#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string temp;
		for (int k = 0; k <= i; k++) {
			temp += '*';
		}
		cout.width(n);
		cout.right;
		cout << temp<<'\n';
	}
}