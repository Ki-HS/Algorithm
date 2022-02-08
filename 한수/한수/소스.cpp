#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	while (n) {
		if (n < 100) {
			count++;
			n--;
			continue;
		}
		vector<int> temp;
		int t = n;
		while (t) {
			temp.push_back(t % 10);
			t /= 10;
		}
		bool s = false;
		for (int i = 0; i < temp.size() - 2; i++) {
			if (temp[i] - temp[i + 1] != temp[i + 1] - temp[i + 2])
			{
				s = true;
				break;
			}
		}
		n--;
		if (s)continue;
		count++;
	}
	cout << count;
}