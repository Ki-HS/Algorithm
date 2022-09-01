#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	int five=0;
	if (!n) {
		cout << 0; return 0;
	}
	do {
 if (n %5==0) 
			five++;
 if (n % 25 == 0)five++;
 if (n % 125 == 0)five++;
		n--;
	} while (n>0);
	
	cout << five;
	//string s = to_string(t);
	//for (int i = 0; i < s.size(); i++) {
	//	if (s[s.size() - i - 1] != '0') {
	//		cout << i; return 0;
	//	}
	//}
}