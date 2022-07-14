#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> v;
char vowels[]={'a','e','i','o','u'};
char s[15];

bool check(string s) {
	int vow = 0, con = 0;

	for (int i = 0; i < s.size(); i++) {
		auto iter = find(begin(vowels), end(vowels), s[i]);
		if (iter == end(vowels)) con++;
		else vow++;

		if (i < s.size() - 1) {
			if (s[i] > s[i + 1])return false;
		}
	}
	if (con < 2 || vow < 1)return false;
	return true;
}

void solution(int d, int a) {
	if(d==l){
		if (check(s)) {
			cout << s << "\n"; 
		}
		return; 
	}
	for (int i = a; i < c; i++) {
		s[d] = v[i];
		solution(d+1, i + 1);
	}
}

int main() {
	cin >> l >> c;

	char t;
	for (int i = 0; i < c; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	solution(0, 0);

}