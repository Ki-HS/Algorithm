#include <iostream>
#include <set>
using namespace std;
int main() {
	int n;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int t;
	set<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> t;
		arr.insert(t);
	}
	int m;
	cin >> m;
	set<int>::iterator iter;
	for (int i = 0; i < m; i++) {
		cin >> t;
		iter = arr.find(t);
		if(iter==arr.end()) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
}