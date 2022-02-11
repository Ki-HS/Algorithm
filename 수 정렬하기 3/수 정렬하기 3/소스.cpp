#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;

	int num[10002];

	memset(num, 0, sizeof(num));

	int a = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (!num[i])continue;
		for(int j=0; j<num[i];j++)
		cout << i << "\n";
	}
}