#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0, cnt = 0;
    while (s != "1") {
        int one = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')zero++;
            else one++;
        }

        s = "";
        while (one) {
            s += one % 2 + '0';
            one /= 2;
        }
        cnt++;
    }
    return { cnt, zero };
}