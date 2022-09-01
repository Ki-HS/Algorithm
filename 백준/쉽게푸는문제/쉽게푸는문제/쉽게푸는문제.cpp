#include <iostream>

using namespace std;

int main() {
	int arr[1001] = {};

	int count = 0;
	int i = 1;
	while (count != 1000) {
		for (int a = 0; a < i; a++) {
			if (count == 1000) {
				break;
			}
			arr[count] = i;
			count++;
		}
		i++;
	}
	int q, w;
	cin >> q >> w;
	if (q > w) {
		int temp = q;
		q = w;
		w = temp;
	}
	int sum = 0;

	for (int i = q-1; i < w; i++) {
		sum += arr[i];
	}
	cout << sum;
}