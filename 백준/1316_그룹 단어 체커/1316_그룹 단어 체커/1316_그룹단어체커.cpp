#include <iostream>
#include <cstring>
using namespace std;

int c = 0;
bool arr[26] = { false, };

int main() {
	int n;
	cin >> n;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		bool q = false;
		for (int j = 0; j < s.length(); j++) {
			if (arr[s[j]- 'a'])continue;
			int k;
			for (k = s.length() - 1; k > j; k--) {
				if (s[k] == s[j]) break;
			}
			for (int l = j; l < k; l++) {
				if (s[l] != s[j]) {
					q = true;
					break;
				}
			}
			if (q) break;
			arr[s[j]-'a'] = true;
		}
		if (!q) c++;
		q = false;
		memset(arr, false, sizeof(arr)/sizeof(bool));
	}
	cout << c;
}