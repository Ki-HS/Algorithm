#include <string>
#include <map>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    int x = 0, y = 0, tx, ty;
    map<pair<pair<int, int>, pair<int, int>>, int> m;
    for (char c : dirs) {
        if (c == 'L') {
            tx = x - 1;
            ty = y;
        }
        else if (c == 'R') {
            tx = x + 1;
            ty = y;
        }
        else if (c == 'U') {
            tx = x;
            ty = y + 1;
        }
        else {
            tx = x;
            ty = y - 1;
        }
        if (tx > 5 || tx < -5 || ty>5 || ty < -5)continue;
        if (x > tx) {
            pair<pair<int, int>, pair<int, int>> p = make_pair(make_pair(x, y), make_pair(tx, ty));
            if (m[p]) {
                x = tx;
                y = ty;
                continue;
            }
            m[p] = 1;
        }
        else if (x < tx) {
            pair<pair<int, int>, pair<int, int>> p = make_pair(make_pair(tx, ty), make_pair(x, y));
            if (m[p])
            {
                x = tx;
                y = ty;
                continue;
            }
            m[p] = 1;
        }
        else {
            if (y > ty) {
                pair<pair<int, int>, pair<int, int>> p = make_pair(make_pair(x, y), make_pair(tx, ty));
                if (m[p]) {
                    x = tx;
                    y = ty;
                    continue;
                }
                m[p] = 1;
            }
            else {
                pair<pair<int, int>, pair<int, int>> p = make_pair(make_pair(tx, ty), make_pair(x, y));
                if (m[p]) {
                    x = tx;
                    y = ty;
                    continue;
                }
                m[p] = 1;
            }
        }
        x = tx;
        y = ty;
        answer++;
    }

    return answer;
}