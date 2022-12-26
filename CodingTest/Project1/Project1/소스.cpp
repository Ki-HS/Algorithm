#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> v) {
	int answer = 0; 
	int max = 0;
	int s = 0;
	bool t = true;
	int tt;
	do {
		if (t) { t = false; tt = v[0]; }
		else if (!t && tt != v[0])break;
		s = 0;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i];
			cout << x;
			int y;
			if (i == v.size() - 1) {
				y = v[0];
			}
			else y = v[i + 1];

			double z = x + y;
			double tmp = sqrt(z);

			if (z == tmp*tmp) s++;
		}
		if (max < s) {
			answer = 1;
			max = s;
		}
		else if (max == s)answer++;
		
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	return answer;
}

int main() {
	vector<int> v = { 1,3,6,8 };
	cout << solution(v);
}