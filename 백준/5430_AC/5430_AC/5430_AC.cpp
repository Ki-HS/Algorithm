#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;


	string p;
	int n;
	string num;

	vector<int> temp;
	vector<int> mt;
	int cnt;
	bool s;
	bool s2;
	int left, right;
	for (int i = 0; i < T; i++) {
		s = true;
		s2 = true;
		temp = mt;
		cnt = 0;

		cin >> p;
		
		cin >> n;
		cin >> num;
		string w;

		for (int j = 0; j < num.size(); j++) {
			if (num[j] >= '0' && num[j] <= '9') {
				w += num[j];
			}
			else {
				if (w=="") continue;
				temp.push_back(stoi(w));
				cnt++;
				w = "";
			}
		}
		if (cnt != n) {
			cout << "error" << "\n";
			continue;
		}
		string temp2;
		left = 0;
		right = temp.size();
		for(int b=0; b<p.size();b++){
			if (p[b] == 'R') {
				s = !s;
			}
			else {
				if (left==right) {
					cout << "error" << "\n";
					s2 = false;
					break;
				}
				if (s) {
					left++;
				}
				else right--;
			}
		}
		if (!s2) continue;
		cout << "[";
		if (s) {
			for (int a = left; a < right; a++) {
				cout << temp[a];
				if (a != right - 1) cout << ",";
			}
		}
		else {
			for (int a = right-1; a >= left; a--) {
				cout << temp[a];
				if (a != left) cout << ",";
			}
		}
		cout << "]" << "\n";
		
	}
}