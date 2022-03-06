#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int check[100101] = { 0, };
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	check[n] = 1;
	queue<int>q;
	q.push(n);
	int size;
	int num;
	while (!q.empty()) {
		size = q.size();
		for (int i = 0; i < size; i++) {
			num = q.front();
			q.pop();
			if (num == k) {
				cout << cnt;
				return 0;
			}
			if (num + 1 <= 100000 && num + 1 > 0 &&!check[num + 1] ) {
				check[num + 1] = 1;
				q.push(num + 1);
			}
			if (num - 1 <= 100000 && num - 1 >= 0 &&!check[num - 1] ) {
				check[num - 1] = 1;
				q.push(num - 1);
			}
			if (num * 2 <=100000 && num > 0 &&!check[num * 2] ) {
				check[num * 2] = 1;
				q.push(num * 2);
			}
		}
		cnt++;
	}
}