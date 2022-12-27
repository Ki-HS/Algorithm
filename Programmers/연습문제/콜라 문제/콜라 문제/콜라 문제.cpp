#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int t = n / a;
        answer += t * b;
        n -= t * a;
        n += t * b;
    }
    return answer;
}