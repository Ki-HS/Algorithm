#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<string>> v;

string solution(int x,int y, int size) {
	string ans;
	string temp = v[x][y];
	bool status = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (v[x+i][y+j] != temp) {
				status = true;
				break;
			}
		}
		if (status)break;
	}
	if(!status)return temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans+=solution(x+size/2*i, y+size/2*j, size / 2);
		}
	}

	return "(" + ans + ")";
}

int main() {
	int n;
	cin >> n;
	v = vector<vector<string>>(n, vector<string>(n));
	for (int i = 0; i < n;i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			v[i][j] = temp[j];
		}
	}
	cout<<solution(0, 0, n);
}