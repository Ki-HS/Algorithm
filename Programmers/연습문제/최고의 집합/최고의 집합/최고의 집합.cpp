#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (!(s / n)) return { -1 };

    while (n) {
        answer.push_back(s / n);

        s -= s / n;
        n--;
    }

    return answer;
}