#include <iostream>
#include <string>
#include <vector>
using namespace std; 

string solution(vector<string> v) {
	int walker = 0;
	while (v.size() != 1) {
		auto iter1 = find(v.begin(), v.end(), "(");
		if (iter1 != v.end()) {
			walker = iter1 - v.begin();
			vector<string> t;
			for (int i = walker + 1; v[walker] != ")"; walker++) {
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
		if (iter2!=v.end()) {
			walker = iter2 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty()) v.push_back(t);
			else v.insert(v.begin() + walker - 1, t);
			continue;
		}
		
		auto iter3 = find(v.begin(), v.end(), "/");
		if (iter3!=v.end()) {
			walker = iter3 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty()) v.push_back(t);
			else v.insert(v.begin() + walker - 1, t);
		}
		
		auto iter4 = find(v.begin(), v.end(), "+");
		if (iter4!=v.end()) {
			walker = iter4 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty()) v.push_back(t);
			else v.insert(v.begin() + walker - 1, t);
			continue;
		}
		
		auto iter5 = find(v.begin(), v.end(), "-");
		if (iter5!=v.end()) {
			walker = iter5 - v.begin();
			string t = v[walker - 1] + v[walker + 1] + v[walker];
			for (int i = 0; i < 3; i++) {
				v.erase(v.begin() + walker - 1);
			}
			if (v.empty()) v.push_back(t);
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