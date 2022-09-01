#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> num(10, 1);

	int cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			if (!num[6] && !num[9]) {
				cnt++;
				for (int j = 0; j < 10; j++)num[j]++;
				num[s[i] - '0']--;
			}
			else if (num[6]) num[6]--;
			else num[9]--;
		}
		else {
			if (!num[s[i] - '0']) {
				cnt++;
				for (int j = 0; j < 10; j++)num[j]++;
				num[s[i] - '0']--;
			}
			else num[s[i] - '0']--;
		}
	}
	
	cout << cnt;
}