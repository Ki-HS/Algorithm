#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	unordered_map<string,int> mon;
	vector<string> name;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		name.push_back(temp);
		mon.insert(make_pair(temp,i+1));
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp[0] >= 'A' && temp[0] <= 'Z') {
			auto iter = mon.find(temp);
			cout << iter->second << "\n";
			
		}
		else {
			cout << name[stoi(temp)-1]<<"\n";
		}
	}
}
