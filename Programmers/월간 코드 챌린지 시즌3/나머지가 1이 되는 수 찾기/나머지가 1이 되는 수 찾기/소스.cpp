#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (n % i == 1)break;
    }
    return i;
}