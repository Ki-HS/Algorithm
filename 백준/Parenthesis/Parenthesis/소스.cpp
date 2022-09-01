#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;

	vector<pair<string, bool>> str;
	string temp;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int l = 0, r = 0;
		int a = 1;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 40) l++;
			else if (temp[j] == 41)r++;
			if (l < r)break;
		}
		if (l != r) a = 0;
		str.push_back(make_pair(temp, a));
	}

	for (int i = 0; i < n; i++) {
		if (str[i].second) cout << "YES" << "\n";
		else cout << "NO" << "\n";	
	}

}