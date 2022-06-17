#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorting(int a, int b) {
	return a > b;
}

int main() {
	long long a;
	cin >> a;
	vector<int> t;
	while (a) {
		t.push_back(a % 10);
		a /= 10;
	}

	sort(t.begin(), t.end(), sorting);
	for (int i = 0; i < t.size(); i++) {
		cout << t[i];
	}
}