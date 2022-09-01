#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string t;
	map<string, int> first;
	map<string,int> second;

	for (int i = 0; i < n; i++) {
		cin >> t;
		first.insert(make_pair(t,0));
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (first.find(t)!=first.end()) {
			second.insert(make_pair(t,i));
		}
	}
	int size = second.size();
	cout << size<<"\n";
	for (int i = 0; i < size; i++) {
		cout << second.begin()->first << "\n";
		second.erase(second.begin());
	}
}