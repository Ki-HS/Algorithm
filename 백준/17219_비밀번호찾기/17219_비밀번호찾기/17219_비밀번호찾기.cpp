#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	map<string, string> mp;
	string url, pwd;
	while (n--) {
		cin >> url >> pwd;
		mp[url] = pwd;
	}
	while (m--) {
		cin >> url;
		cout << mp[url] << "\n";
	}
}