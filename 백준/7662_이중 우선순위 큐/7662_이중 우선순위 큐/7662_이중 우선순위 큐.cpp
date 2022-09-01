#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int t;
	int num;

	char cmd;
	map<int, int> q;
	map<int, int> mt;

	for (int i = 0; i < n; i++) {
		q = mt;
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> cmd;
			if (cmd == 'I') {
				cin >> num;
				auto iter = q.find(num);
				if (q.find(num) != q.end())
					iter->second++;
				else q.insert(make_pair(num, 1));
			}
			else {
				cin >> num;
				if (q.size() == 0) continue;
				if (num == 1) {
					auto iter = q.end();
					iter--;
					if (iter != q.end()) {
						if (iter->second > 1)
							iter->second--;
						else q.erase(iter->first);
					}
				}
				else {
					auto iter = q.begin();
					if (iter->second > 1)
						iter->second--;
					else q.erase(iter->first);
				}
			}
		}
		if (q.size() == 0)cout << "EMPTY" << "\n";
		else {
			auto max = q.end();
			max--;
			auto min = q.begin();
			cout << max->first << " " << min->first << "\n";
		}
	}
}