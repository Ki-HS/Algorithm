#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string equation;
	cin >> equation;
	vector <string> eq;
	int i = 0;
	while (equation[i]) {
		string temp;
		if (equation[i] == '+' || equation[i] == '-') {
			temp = equation[i];
			i++;
			eq.push_back(temp);
			continue;
		}
		while (equation[i]&&equation[i]!='+'&&equation[i]!='-') {
			temp += equation[i];
			i++;
		}
		
		eq.push_back(temp);
		
	}
	int a = 0;
	int sum = 0;
	bool plus = true;
	string m; m += '-';
	string p; p += '+';
	while (a!=eq.size()) {
		if (eq[a] == m) {
			plus = false;
			a++;
			continue;
		}
		int temp;
		stringstream ssInt(eq[a]);
		ssInt >> temp;
		if (plus) {
			sum += temp;
		}
		else {
			sum -= temp;
		}
		a++;
	}
	cout << sum;
}