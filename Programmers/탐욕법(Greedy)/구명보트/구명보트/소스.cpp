#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> p, int limit) {
    int answer = 0;
    sort(p.begin(), p.end(), greater<>());
    int b = 0, e = p.size() - 1;
    while (b<=e) {
        if (b!=e&&p[b] + p[e] <= limit)e--;
        b++;
        answer++;
    }
    return answer;
}

int main() {
    vector<int> p = {70,80,50 };
    cout << solution(p, 100);
}