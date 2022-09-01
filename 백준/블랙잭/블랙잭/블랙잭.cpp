#include <iostream>
#define null NULL
using namespace std;

int main() {
	int N;
	int M;

	cin >> N >> M;

	int arr[101] = {};

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (j == i) continue;
				else if (k == i || k == j) continue;
				if (arr[i] + arr[j] + arr[k] <= M && sum < arr[i] + arr[j] + arr[k]) {
					sum = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}

	cout << sum;
}