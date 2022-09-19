#include <string>
#include <vector>

using namespace std;

int fibo(int a) {
    if (a == 0)return 0;
    if (a == 1)return 1;
    return fibo(a - 1) + fibo(a - 2);
}

int solution(int n) {
    vector<int> v(n + 1, 0);
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = v[i - 1] % 1234567 + v[i - 2] % 1234567;
    }
    return v[n] % 1234567;
}