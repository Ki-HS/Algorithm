#include <iostream>
#include <vector>
using namespace std;

//int prime(int i) {
//	int e = 0;
//	if (i == 1 || i == 2)e++;
//	for (int a = i+1; a <= 2 * i; a++) {
//		int t = 2;
//		bool w = false;
//		while (t != a/2+1) {
//			if (a % t == 0) { 
//				w = true;
//				break;
//			}
//			t++;
//		}
//		if (!w)e++;
//	}
//	return e;
//}
//
//int main() {
//	vector<int> a;
//	int i;
//	do {
//		cin >> i;
//		a.push_back(prime(i));
//	} while (i);
//	for (int q = 0; q < a.size() - 1; q++) {
//		cout << a[q] << "\n";
//	}
//}

int main() {
	vector<int> arr;
	int count = 0; 
	
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	for (int i = 3; i < 246913; i++) {
		bool p = false;
		for (int j = 2; j < arr.size(); j++) {
			if (i % j == 0) p = true;
		}
		if (!p) arr.push_back(i);
	}
	vector<int> w;
	int q;
	do {
		cin >> q;
		int a = 2;
		int cnt = 0;
		while (arr[a] <= q) {
			a++;
		}
		for (a; arr[a] <= 2 * q; a++) {
			cnt++;
		}
		w.push_back(cnt);
	} while (q);
	for (int z = 0; z < w.size() - 1; z++) {
		cout << w[z] << "\n";
	}
}