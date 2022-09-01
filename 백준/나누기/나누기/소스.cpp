#include <iostream>

using namespace std;

int main() {
	long long N, F;
	cin >> N;
	cin >> F;
	long long a = 0;
	N= N / 100;
	N = N * 100;
	while (a < 100) {
		if ((N + a) % F==0) {
			break;
		}
		a++;
	}
	if (a < 10) {
		cout << "0" << a;
	}
	else {
		cout << a;
	}
}