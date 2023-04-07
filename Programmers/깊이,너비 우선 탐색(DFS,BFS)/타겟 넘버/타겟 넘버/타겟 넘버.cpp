#include <string>
#include <vector>

using namespace std;

int func1(vector<int> n, int t) {
    if (n.size() == 0 && t == 0) return 1;
    else if (n.size() == 0)return 0;

    int tmp = n[0];
    n.erase(n.begin());

    return func1(n, t + tmp) + func1(n, t - tmp);
}

int solution(vector<int> numbers, int target) {
    int answer = func1(numbers, target);

    return answer;
}