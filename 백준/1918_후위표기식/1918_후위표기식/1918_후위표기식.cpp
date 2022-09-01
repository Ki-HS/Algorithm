#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

string solution(vector<string> v) {
	int walker = 0;
	while (v.size() != 1) {
		auto iter1 = find(v.begin(), v.end(), "(");
		auto titer = iter1;
		while (iter1 != v.end()) {
			titer = iter1;
			iter1 = find(iter1+1, v.end(), "(");
		}
		if (titer != v.end()) {
				walker = titer - v.begin();
			vector<string> t;
			for (int i = walker + 1; i<v.size()&&v[i] != ")";) {
				t.push_back(v[i]);
				v.erase(v.begin() + i);
			}
			string a = solution(t);
			v.erase(v.begin() + walker);
			v.erase(v.begin() + walker);
			v.insert(v.begin() + walker, a);
			continue;
		}	
				
		auto iter2 = find(v.begin(), v.end(), "*");
		auto iter3 = find(v.begin(), v.end(), "/");
		if (iter2!=v.end()|| iter3 != v.end()) {
			walker = (iter2 < iter3) ? iter2 - v.begin() : iter3 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty() || v.size() == walker - 1) v.push_back(t);
			else v.insert(v.begin() + walker - 1, t);
			continue;
		}
		
		auto iter4 = find(v.begin(), v.end(), "+");
		auto iter5 = find(v.begin(), v.end(), "-");
		if (iter4!=v.end()||iter5!=v.end()) {
			walker = (iter4 < iter5) ? iter4 - v.begin() : iter5 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty() || v.size() == walker - 1) v.push_back(t);
			else v.insert(v.begin() + walker - 1, t);
			continue;
		}
	}
	return v[0];
}

int main() {
	string s;

	cin >> s;
	vector<string> vs;
	for (int i = 0; i < s.size(); i++) {
		string w(1, s[i]);
		vs.push_back(w);
	}

	string ans = solution(vs);
	cout << ans;
}