#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    double t = (double)d / (double)k;
    for (long long i = 0; i <= d; i += k) {
        long long y = sqrt((long long)d * d - i * i) / k;
        answer += y + 1;
    }
    return answer;
}