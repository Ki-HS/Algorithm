#include <iostream>
#include <string>
#include <vector>
using namespace std;

int testcase, N, M;

bool check(vector<pair<int,int>> file) {
	int cur = file[0].first;
	for (int i = 1; i < file.size(); i++) {
		if (cur < file[i].first) {
			return true;
		}
	}
	return false;
}

void solution(vector<pair<int, int>>& file, int idx, int order) {
	while (file.size()) {
		if (check(file)) {
			file.push_back(file[0]);
			file.erase(file.begin());
		}
		else {
			if (file[0].second == idx) {
				cout << order << "\n";
				return;
			}
			order++;
			file.erase(file.begin());
		}
	}
}

int main() {
	cin >> testcase;

	while (testcase--) {
		cin >> N >> M;
		int t;
		vector<pair<int, int>> file;

		for (int i = 0; i < N; i++) {
			cin >> t;
			file.push_back(make_pair(t, i));
		}
		solution(file, M, 1);
	}
}