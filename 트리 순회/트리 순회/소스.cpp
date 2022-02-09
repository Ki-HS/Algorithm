#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int t = 0;
void pre(vector<vector<string>> tree) {
	
}
void in(vector<vector<string>> tree) {

}
void post(vector<vector<string>> tree) {

}

class node {
public:
	node* left;
	node* right;
	string data;
	node() { left = nullptr; right = nullptr; data = ""; };
};
class Tree {
public:
	node* root;
	Tree() { root = nullptr; };
	node* find(string a) {
		node* target = root;
		while (target) {

		}
	}
};

int main() {
	cin >> n;
	vector<vector<string>> tree(n, vector<string>(4, ""));
	Tree T;
	string a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		node* newNodeA = new node;
		node* newNodeB=nullptr;
		node* newNodeC=nullptr;
		newNodeA->data = a;
		if (b != ".") {
			newNodeB = new node;
			newNodeB->data = b;
		}
		if (c != ".") {
			newNodeC = new node;
			newNodeC->data = c;
		}
		if (!T.root) {
			T.root = newNodeA;
			T.root->left=newNodeB;
			T.root->right = newNodeC;
			continue;
		}
		

	}
	pre(tree);
}
