#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t;

bool sort1(int a, int b) {
    return abs(t - a) < abs(t - b);
}

bool sort2(int a, int b) {
    if (abs(t - a) == abs(t - b)) return a > b;
    else return abs(t - a) < abs(t - b);
}

vector<int> solution(vector<int> num, int n) {
    t = n;
    sort(num.begin(), num.end(), sort1);
    stable_sort(num.begin(), num.end(), sort2);
    return num;
}

int main() {
    vector<int> v = { 1,2,3,4,5,6 };
    solution(v, 4);
}