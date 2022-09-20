#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n) {
        if (n % 2) {
            n--;
            ans++;
        }
        else n /= 2;
    }
    return ans;
}