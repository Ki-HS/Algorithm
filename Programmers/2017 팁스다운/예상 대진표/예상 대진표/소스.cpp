#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    a--;
    b--;
    answer++;
    while (a / 2 != b / 2) {
        if (a != 0)a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}