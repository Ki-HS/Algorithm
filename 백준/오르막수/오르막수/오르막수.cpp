#include <iostream>
#include <string>
#define null NULL
using namespace std;
int db[1001][10];
int main() {
	int num;
	int i, j, k;
	cin >> num;

	for (i = 0; i <= 9; ++i)db[1][i] = 1;
	for (i = 2; i <= num; ++i) {
		for (j = 0; j <= 9; ++j) {
			for (k = j; k <= 9; ++k) {
				db[i][k] += db[i - 1][j];
				db[i][k] %= 10007;
			}
		}
	}
	int sum = 0;
	for (i = 0; i <= 9; ++i)sum += db[num][i];
	cout << sum % 10007 << '\n';


	
	
}