#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define null NULL
map<vector<int>, int > m;

vector<int> v;

class node {
public:
    node* parent = NULL;
    node* right = null;
    node* left = null;
    vector<int> value;
};

bool cmp(vector<int>a, vector<int>b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
}

void pre(node* n) {
    if (!n)return;
    v.push_back(m[n->value]);
    pre(n->left);
    pre(n->right);
}

void post(node* n) {
    if (!n)return;
    post(n->left);
    post(n->right);
    v.push_back(m[n->value]);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    int idx = 1;
    for (vector<int> v : nodeinfo) {
        m[v] = idx++;
    }

    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    node root= node();
    root.value = nodeinfo[0];
    
    for (int i = 1; i < nodeinfo.size(); i++) {
        vector<int> t = nodeinfo[i];
        node *cur = &root;
        while (1) {
            if (t[0] < cur->value[0]) {
                if (cur->left) cur = cur->left;
                else {
                    node *newNode = new node();
                    newNode->value = t;
                    newNode->parent = cur;
                    cur->left = newNode;
                    break;
                }
            }
            else {
                if (cur->right) cur = cur->right;
                else {
                    node* newNode = new node();
                    newNode->value = t;
                    newNode->parent = cur;
                    cur->right = newNode;
                    break;
                }
            }
        }
    }

    pre(&root);
    answer.push_back(v);
    v.clear();
    post(&root);
    answer.push_back(v);
    

    return answer;
}

int main() {
    solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
}