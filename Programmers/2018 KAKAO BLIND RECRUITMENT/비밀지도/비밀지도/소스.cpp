#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		vector<int>v(n, 0);
		int temp = arr1[idx];
		int j = 0;
		while (temp) {
			v[j] = temp % 2;
			temp /= 2;
			j++;
		}
		temp = arr2[idx];
		j = 0;
		while (temp) {
			v[j] = v[j] | (temp % 2);
			temp /= 2;
			j++;
		}
		for (int k = 0; k < n; k++) {
			if (v[k])answer[idx] += '#';
			else answer[idx] += ' ';
		}
		reverse(answer.begin(), answer.end());
		idx++;
	}
	return answer;
}

int main() {
	vector<int> arr1 = { 9,20,28,18,11 };
	vector<int> arr2 = { 30,1,21,17,28 };
	vector<string> ans = solution(5, arr1, arr2);
	for (auto i : ans)cout << i<<endl;
}