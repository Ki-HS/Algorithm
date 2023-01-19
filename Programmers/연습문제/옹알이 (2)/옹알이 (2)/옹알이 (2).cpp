#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> v = { "aya", "ye","woo","ma" };
    string tmp = "";
    for (string str : babbling) {
        int idx = 0;
        bool b = false;
        tmp = "";
        while (idx < str.size()) {
            if (str[idx] == 'a' && tmp != "aya" && idx + 3 <= str.size() && str[idx + 1] == 'y' && str[idx + 2] == 'a') {
                tmp = "aya";
                idx += 3;
                continue;
            }
            if (str[idx] == 'y' && tmp != "ye" && idx + 2 <= str.size() && str[idx + 1] == 'e') {
                tmp = "ye";
                idx += 2;
                continue;
            }
            if (str[idx] == 'm' && tmp != "ma" && idx + 2 <= str.size() && str[idx + 1] == 'a') {
                tmp = "ma";
                idx += 2;
                continue;
            }
            if (str[idx] == 'w' && tmp != "woo" && idx + 3 <= str.size() && str[idx + 1] == 'o' && str[idx + 1] == 'o') {
                tmp = "woo";
                idx += 3;
                continue;
            }
            b = true;
            break;
        }
        if (!b)answer++;
    }

    return answer;
}