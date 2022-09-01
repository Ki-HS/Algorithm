#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	
	int t;

	int s=0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 0) {
			if (v.size()) {
				v.pop_back();
				continue;
			}
		}
		v.push_back(t);
	}

	for (int i = 0; i < v.size(); i++) {
		s += v[i];
	}
	cout << s;
}