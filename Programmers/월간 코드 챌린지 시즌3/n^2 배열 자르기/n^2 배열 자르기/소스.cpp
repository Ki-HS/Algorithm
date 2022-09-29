#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int t, b;

    for (long long i = left; i <= right; i++) {
        t = i / n;
        b = i % n;
        if (t >= b + 1)b += t - b;
        answer.push_back(b + 1);
    }

    return answer;
}