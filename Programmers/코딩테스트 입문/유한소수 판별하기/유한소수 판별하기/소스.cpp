#include <string>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

int solution(int a, int b) {
    int answer = 0;
    int g = gcd(a, b);
    if (a % b == 0)return 1;
    else {
        b /= g;
        if (b == 2 || b == 5)return 1;
        int i = 2;
        while (b != 1) {
            if (b % 2 == 0) {
                b /= 2;
                continue;
            }
            if (b % 5 == 0) {
                b /= 5;
                continue;
            }
            return 2;
        }
    }
    return 1;
}