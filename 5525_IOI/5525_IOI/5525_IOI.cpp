#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	string s;
	cin >> s;
	s = s.substr(0, m-1);
	int cnt = 0;
	string ioi;
	for(int i=0; i<n; i++)ioi += "OI";
	bool status;
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			if (i % 2) {
				int j = 0;
				for (j = i; j < m; j++) {
					if (j % 2 == 0 && s[j] != 'O')break;
					if (j % 2 && s[j] != 'I')break;
				}
				double t = (double)(j - i - 2 * n - 1) / (double)2;
				if (t >= 0)cnt += t+1;
				if (s[j] == 'I')i = j - 1;
				else i = j;
			}
			else {
				int j;
				for (j = i; j < m; j++) {
					if (j % 2 && s[j] != 'O')break;
					if (j % 2 ==0&& s[j] != 'I')break;
				}
				double t = (double)(j - i - 2*n-1) / (double)2;
				if (t >= 0)cnt += t+1;
				if (s[j] == 'I')i = j - 1;
				else i = j;
			}
			
		}
	}
	cout << cnt;
}