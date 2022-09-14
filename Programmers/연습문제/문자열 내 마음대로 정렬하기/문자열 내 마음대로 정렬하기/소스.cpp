#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;

bool cmp1(string a, string b) {
    return a[idx] < b[idx];
}

bool cmp2(string a, string b) {
    if (a[idx] == b[idx]) return a < b;
    else return a[idx] < b[idx];
}

vector<string> solution(vector<string> s, int n) {
    idx = n;
    sort(s.begin(), s.end(), cmp1);
    stable_sort(s.begin(), s.end(), cmp2);

    return s;
}