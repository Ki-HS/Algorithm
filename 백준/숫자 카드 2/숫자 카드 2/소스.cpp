#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	map<int, int> card;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		auto iter = card.find(a);

		if (iter != card.end()) {
			iter->second++;
		}
		else card.insert(make_pair(a, 1));
	}

	cin >> m;
	vector<int> v;
	for (int i = 0; i < m; i++) {
		cin >> a;
		v.push_back(a);
	}
	
	for (int i = 0; i < m; i++) {
		auto iter = card.find(v[i]);

		if (iter != card.end()) {
			cout << iter->second << " ";
		}
		else cout << 0 << " ";
	}
	


}