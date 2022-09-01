#include <iostream>

using namespace std;

int main() {
	int arr[9] = {};
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	int num;
	if (arr[0] == 1) {
		num = 1;
		for (int i = 0; i < 8; i++) {
			if (num != arr[i]) { cout << "mixed"; return 0; }
			num++;
		}
		cout << "ascending";
	}
	else if (arr[0] == 8) {
		num = 8;
		for (int i = 0; i < 8; i++) {
			if (num != arr[i]) { cout << "mixed"; return 0; }
			num--;
		}
		cout << "descending";
	}
	else { cout << "mixed"; return 0; }
}