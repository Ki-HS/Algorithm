#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;
	vector<vector<int>> m;
	int r, g, b; 
	for (int i = 0; i < n; i++) {
		cin >> r >> g >> b;
		vector<int> rgb;
		rgb.push_back(r);
		rgb.push_back(g);
		rgb.push_back(b);
		
		v.push_back(rgb);
	}

	for (int i = 0; i < n - 1; i++) {
		v[i + 1][0] += min(v[i][1], v[i][2]);
		v[i + 1][1] += min(v[i][0], v[i][2]);
		v[i + 1][2] += min(v[i][1], v[i][0]);
	}
	cout << min(v[n - 1][0], min(v[n - 1][1], v[n - 1][2]));
}