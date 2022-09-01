#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C << "\n" << ((A % C) + (B % C)) % C << "\n" << (A*B) % C << "\n" << ((A % C) *(B % C)) % C;
}