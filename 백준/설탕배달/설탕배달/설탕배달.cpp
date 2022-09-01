#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int count = 0;
	while (num >= 0) {
		if (num % 5 == 0) {
			count += (num / 5);
			cout << count;
			return 0;
		}
		count++;
		num -= 3;
	}

	cout << -1;

}