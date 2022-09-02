#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int>q;
    while (n) {
        q.push(n % 3);
        n /= 3;
    }
    vector<int> v;
    int i = 0;
    while (!q.empty()) {
        int x = q.top();
        answer += x * pow(3, i);
        q.pop();
        i++;
    }
    return answer;
}