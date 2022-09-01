#include <iostream>
#include <vector>
#include <algorithm>
#define null NULL
using namespace std;
static bool cmp(const vector<int>& v1,const vector <int>& v2) {
	return v1[1] < v2[1];
}
int main() {
	int x;
	cin >> x;

	vector<vector<int>> v1;
	vector <int> v2;

	for (int i = 0; i < x; i++) {
		v1.push_back(v2);
		for (int j = 0; j < 2; j++) {
			int num;
			cin >> num;
			v1[i].push_back(num);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v1.begin(), v1.end(), cmp);
	
	int count = 0;

	int temp = 0;

	for (int i = 0; i < x; i++) {
		if (temp > v1[i][0]) continue;
		if (temp < v1[i][1])temp = v1[i][1];
		count++;
	}
	cout << count;
}