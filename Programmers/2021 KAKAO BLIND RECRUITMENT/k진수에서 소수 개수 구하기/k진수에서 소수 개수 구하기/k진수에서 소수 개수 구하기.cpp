#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    stack<int> s;
    while (n) {
        s.push(n % k);
        n /= k;
    }

    vector<int> v;
    long long int t = 0;
    while (!s.empty()) {
        if (s.top() == 0) {
            t = 0;
            for (int i = 0; v.size(); i++) {
                t += v[v.size() - 1] * pow(10, i);
                v.pop_back();
            }
            bool status = false;
            for (int i = 2; i <= sqrt(t); i++) {
                if (t % i == 0) {
                    status = true;
                    break;
                }
            }
            if (!status && t != 1 && t) answer++;
            v.clear();
        }
        v.push_back(s.top());
        s.pop();
    }

    t = 0;
    for (int i = 0; v.size(); i++) {
        t += v[v.size() - 1] * pow(10, i);
        v.pop_back();
    }
    bool status = false;
    for (int i = 2; i <= sqrt(t); i++) {
        if (t % i == 0) {
            status = true;
            break;
        }
    }
    if (!status && t != 1 && t) answer++;
    v.clear();

    return answer;
}