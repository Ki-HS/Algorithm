#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for (auto i : babbling) {
        int j = 0;
        string temp;
        bool s = false;
        while (j < i.size()) {
            if (i[j] == 'a') {
                if (temp != "aya" && j < i.size() - 2 && i[j + 1] == 'y' && i[j + 2] == 'a') {
                    temp = "aya";
                    j += 3;
                    continue;
                }
                else { s = true; break; }
            }
            else if (i[j] == 'y') {
                if (temp != "ye" && j < i.size() - 1 && i[j + 1] == 'e') {
                    temp = "ye";
                    j += 2;
                    continue;
                }
                else { s = true; break; }
            }
            else if (i[j] == 'w') {
                if (temp != "woo" && j < i.size() - 2 && i[j + 1] == 'o' && i[j + 2] == 'o') {
                    temp = "woo";
                    j += 3;
                    continue;
                }
                else { s = true; break; }
            }
            else if (i[j] == 'm') {
                if (temp != "ma" && j < i.size() - 1 && i[j + 1] == 'a') {
                    temp = "ma";
                    j += 2;
                    continue;
                }
                else { s = true; break; }
            }
            else { s = true; break; }
            if (s)break;
        }
        if (!s)answer++;
    }
    return answer;
}