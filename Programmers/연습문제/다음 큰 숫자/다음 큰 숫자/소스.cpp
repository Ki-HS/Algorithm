#include <string>
#include <vector>

using namespace std;

int binary(int num) {
    int one = 0;
    while (num) {
        if (num % 2)one++;
        num /= 2;
    }
    return one;
}

int solution(int n) {
    int answer = 0;
    int no = binary(n);
    int a = -1;
    while (a != no) {
        a = binary(++n);
    }

    return n;
}