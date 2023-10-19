#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>a, vector<int>b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(),cmp);
    
    int a = 1;
    int b = 30000;

    for (auto v : routes) {
        if (v[0] > b) {
            a++;
            b = v[1];
        }
        b = b > v[1] ? v[1] : b;
    }

    return a;
}

int main() {
    cout << solution({ {-20,-15},{-14,-5},{-18,-13},{-5, - 3} });
}