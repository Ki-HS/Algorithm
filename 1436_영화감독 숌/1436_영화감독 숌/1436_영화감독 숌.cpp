#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkDevil(string a) {
	bool s = false;
	int k = 0;
	for (int i = 0; i < a.size()-2; i++) {
		if (a[i] == '6' && a[i + 1] == '6' && a[i + 2] == '6') k++;
	}
	if (k >= 1)s = true;
	return s;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string devil = "666";

	vector<string> mov;
	int i = 0;
	int d = 666;
	string temp;
	while (i != n+1) {
		temp = to_string(d);
		if (checkDevil(temp)) {
			mov.push_back(temp); 
			i++; 
		}
		d++;
	}
	cout << mov[n - 1];
}