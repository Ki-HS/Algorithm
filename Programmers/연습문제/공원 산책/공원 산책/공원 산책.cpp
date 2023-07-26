#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int x, y;
    for (int i = 0; i < park.size(); i++) {
        auto z = find(park[i].begin(), park[i].end(), 'S');
        if (z != park[i].end()) {
            x = i;
            y = z - park[i].begin();
            break;
        }
    }

    for (string s : routes) {
        char f = s[0];
        int r = s[2] - '0';
        bool flag = false;
        if (f == 'N') {
            if (x - r < 0) continue;
            for (int i = x; i >= x - r; i--) {
                if (park[i][y] == 'X') {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            x -= r;
        }
        else if (f == 'S') {
            if (x + r > park.size() - 1) continue;
            for (int i = x; i <= x + r; i++) {
                if (park[i][y] == 'X') {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            x += r;
        }
        else if (f == 'W') {
            if (y - r < 0) continue;
            for (int i = y; i >= y - r; i--) {
                if (park[x][i] == 'X') {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            y -= r;
        }
        else {
            if (y + r > park[0].size() - 1) continue;
            for (int i = y; i <= y + r; i++) {
                if (park[x][i] == 'X') {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            y += r;
        }
    }


    return { x,y };
}

int main() {
    solution({ "OSO", "OOO", "OXO", "OOO" },{ "E 2","S 3","W 1" });
}