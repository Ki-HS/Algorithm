#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;

	int t1, t2, t3=0,t4;
	cin >> a >> b;
	string temp;
	bool s = true;
	int i = 0;
	while (s) {
		t1 = t2 = 0;
		if(t3)t1++;
		t3 = 0;
		if (i < a.size()) {
			t1 += a[a.size()-1-i]-'0';
		}
		if (i < b.size()) {
			t2 += b[b.size()-1-i] - '0';
		}
		if (t1 + t2>= 10) { t3++;}
		int z = (t1 + t2) % 10;
		if (i >= b.size() && i >= a.size()) { if(z)temp += z + '0';  break; }
		temp += z+'0';
		i++;
	}
	string temp2;
	for (i = temp.size() - 1; i >= 0; i--) {
		temp2 += temp[i];
	}
	cout << temp2;
}