#include <string>

using namespace std;

int solution(string d) {
    int answer = 0;
    int t = 0;
    int prev = 0;
    int pprev = 0;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] >= '0' && d[i] <= '9') {
            if (i != 0 && d[i - 1] == '*')prev = pprev;
            else prev = t;
            answer += t;
            t = d[i] - '0';
            if (i != 0 && d[i] == '0' && d[i - 1] == '1') { t = 10; answer--; }
        }
        else if (d[i] == '*') {
            pprev = t * 2;
            t *= 2;
            t += prev;
        }
        else if (d[i] == '#') {
            t *= -1;
        }
        else if (d[i] == 'D') {
            t *= t;
        }
        else if (d[i] == 'T') {
            t *= t * t;
        }
    }

    answer += t;
    return answer;
}