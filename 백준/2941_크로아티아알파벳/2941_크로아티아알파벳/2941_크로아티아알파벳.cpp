#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		bool st = false;
		if ((s[i] == 's' || s[i] == 'z') && i != s.size() - 1 && s[i + 1] == '=') { cnt++; i++; st = true; }
		else if (s[i] == 'd') {
			if (i != s.size() - 2 && s[i + 1] == 'z' && s[i + 2] == '=') {
				cnt++;
				i += 2;
				st = true;
			}
			else if (i != s.size() - 1 && s[i + 1] == '-') {
				cnt++;
				i++;
				st = true;
			}
		}
		else if ((s[i] == 'n' || s[i] == 'l') && i != s.size() - 1 && s[i + 1] == 'j') {
			cnt++;
			i++;
			st = true;
		}
		else if (s[i] == 'c' && i != s.size() - 1 && (s[i + 1] == '=' || s[i + 1] == '-')) {
			cnt++;
			i++;
			st = true;
		}
		if (!st)cnt++;
	}
	cout << cnt;
}