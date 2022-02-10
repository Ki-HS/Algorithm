#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<vector<string>> tree(26, vector<string>(3, ""));

void pre(string root) {
	if (root == ".")return;
	cout << root;
	pre(tree[root[0] - 65][1]);
	pre(tree[root[0] - 65][2]);
}
void in(string root) {
	if (root == ".")return;
	in(tree[root[0] - 65][1]);
	cout << root;
	in(tree[root[0] - 65][2]);
}
void post(string root) {
	if (root == ".")return;
	post(tree[root[0] - 65][1]);
	post(tree[root[0] - 65][2]);
	cout << root;
}


int main() {
	cin >> n;
	string a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a>>b>>c;

		tree[a[0] - 65][0] = a;
		tree[a[0] - 65][1] = b;
		tree[a[0] - 65][2] = c;
	}
	pre("A");
	cout << "\n";
	in("A");
	cout << "\n";
	post("A");
}
