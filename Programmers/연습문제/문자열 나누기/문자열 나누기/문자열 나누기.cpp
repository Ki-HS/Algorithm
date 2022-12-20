#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool q = true;
    char c;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (q)
        {
            c = s[i];
            q = false;
        }
        if (s[i] == c) {
            a++;
        }
        else b++;
        if (a == b) {
            a = 0;
            b = 0;
            q = true;
            answer++;
        }

    }
    if (a > b)
        answer++;
    return answer;
}