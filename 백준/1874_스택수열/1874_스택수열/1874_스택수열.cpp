#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> s;

	vector<char>ans;
	while (n--)cin >> v[v.size()-n-1];

	int num = 1;

	for (int i = 0; i < v.size(); i++) {
		while ((s.empty() || s[s.size() - 1] != v[i])&&num<=v.size()+1) {
			s.push_back(num);
			num++;
			ans.push_back('+');
		}
		if (num > v.size()+1) {
			cout << "NO";
			return 0;
		}
		s.pop_back();
		ans.push_back('-');
	}
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << "\n";
}