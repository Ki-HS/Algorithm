#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		if (v[i] < m)cout << v[i] << ' ';
	}
}