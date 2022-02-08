#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);

	for (int i = 4; i <= 11; i++) {
		int cnt = 0;
		int temp = i;
		for (int j = 0; j < 3; j++) {
			cnt += a[i - j-2];
		}
		a.push_back(cnt);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << a[v[i]-1] << "\n";
	}
}