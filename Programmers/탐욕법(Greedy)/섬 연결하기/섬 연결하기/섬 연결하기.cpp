#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int>b) {
    return a[2] < b[2];
}

int getRoot(vector<int>& p, int a) {
    if (p[a] == a)return a;
    else return getRoot(p, p[a]);
}

bool cycle(vector<int>& p, int a, int b) {
    int pa = getRoot(p, a);
    int pb = getRoot(p, b);
    if (pa == pb)return true;
    else return false;
}

void unionParents(vector<int>& p, int a, int b) {
    int pa = getRoot(p, a);
    int pb = getRoot(p, b);
    if (pa < pb)p[pb] = pa;
    else p[pa] = pb;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    vector<int> p(101);

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (auto v : costs) {
        if (!cycle(p, v[0], v[1])) {
            unionParents(p, v[0], v[1]);
            answer += v[2];
        }
    }

    return answer;
}