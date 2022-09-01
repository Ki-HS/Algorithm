#include <iostream>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;

	double score = 0.0;
	if (s[0] == 'A') {
		score += 4.0;
		if (s[1] == '+')
			score += 0.3;
		else if (s[1] == '-')
			score -= 0.3;
	}
	else if (s[0] == 'B') {
		score += 3.0;
		if (s[1] == '+')
			score += 0.3;
		else if (s[1] == '-')
			score -= 0.3;
	}
	else if (s[0] == 'C') {
		score += 2.0;
		if (s[1] == '+')
			score += 0.3;
		else if (s[1] == '-')
			score -= 0.3;
	}
	else if (s[0] == 'D') {
		score += 1.0;
		if (s[1] == '+')
			score += 0.3;
		else if (s[1] == '-')
			score -= 0.3;
	}
	
	cout.precision(1);
	cout << fixed;
	cout << score;
	
}