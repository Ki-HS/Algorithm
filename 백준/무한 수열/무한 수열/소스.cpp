#include <iostream>
#include <map>
using namespace std;

map<long long, long long> cache;
long long inf(long n, long long p, long long q) {
	if (cache.count(n))return cache[n];
	return cache[n]=inf(n / p, p, q) + inf(n / q, p, q);
}

int main() {
	long long n, p, q;
	cin >> n >> p >> q;
	cache[0] = 1;
	cout<<inf(n, p, q);
	return 0;
}