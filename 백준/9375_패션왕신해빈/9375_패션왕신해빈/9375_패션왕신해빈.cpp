#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	map<string, int> mp;
	while (n--) {
		int sum = 0;
		cin >> m;
		while (m--) {
			string a, b;
			cin >> a >> b;
			mp[b]++;
		}
		int x=1;
		for (auto i : mp) {
			//해당 타입을 입지 않는다는 경우도 포함하기 때문에 1추가
			x *= (i.second) + 1;
		}

		/*for (int i = 0; i < (1 << v.size()); ++i) {
			int x = 1;
			bool s = false;
			for (int j = 0; j < v.size(); j++) {
				if (i & (1 << j)) { s = 1; x *= v[j]; }
			}
			if (s)sum += x;
		}*/

		//모든 옷을 입지 않는 경우가 있기 때문에 1 감소.
		cout << x-1 << '\n';

		mp.clear();
	}

}