#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;

	double t;
	vector<pair<double, double>>v;
	vector<double> v2;
	map<double,int> m;
	double mean=0,center, bin,range;
	for (double i = 0; i < n;i++) {
		cin >> t;
		v2.push_back(t);
		mean += t;
		m[t]++;
	}

	int max = 0;
	bool sec = false;
	for (auto i : m) {
		if (max < i.second) {
			bin = i.first;
			max = i.second;
			sec = false;
		}
		else if (max == i.second&&sec==false) {
			bin = i.first;
			sec = true;
		}
	}
	sort(v2.begin(), v2.end());
	mean /= n;
	mean = round(mean);
	range = v2[v2.size() - 1] - v2[0];
	
		double a = round(v2.size() / 2);
	if (v2.size()) {
		center = v2[a];
	}
	else {
		center = round((double(v2[a]) + double(v2[a - 1])) / 2);
	}

	cout << (int)mean << endl
		<< (int)center << endl
		<< (int)bin << endl
		<< (int)range;
}