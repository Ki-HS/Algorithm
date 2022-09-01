#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool sortingA(string &a, string &b) {
	return a.size() < b.size();
}
bool sortingB(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else return false;
}

int main() {
	int n;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;

	vector <string> word;
	
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		auto it = find(word.begin(), word.end(), temp);
		if(it==word.end())word.push_back(temp);
	}
	
	sort(word.begin(), word.end(), sortingA);
	stable_sort(word.begin(), word.end(), sortingB);

	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << "\n";
	}
}