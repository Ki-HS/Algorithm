#include <string>
#include <vector>
#include <cmath>

#define INF 10000000001
using namespace std;
long long minX = INF, minY = INF, maxX = -INF, maxY = -INF;
pair<long long, long long> eqation(vector<int> a, vector<int> b) {
    long long t = (a[0] * b[1] - a[1] * b[0]);
    if (t == 0)return make_pair(INF, INF);
    long long x = ((long(a[1]) * long(b[2])) - (long(a[2]) * long(b[1])));
    long long y = ((long(a[2]) * long(b[0])) - (long(a[0]) * long(b[2])));

    if (x % t || y % t) return make_pair(INF, INF);
    x /= t;
    y /= t;
    minX = minX > x ? x : minX;
    maxX = maxX < x ? x : maxX;

    minY = minY > y ? y : minY;
    maxY = maxY < y ? y : maxY;

    return make_pair(x, y);
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>>vpd;

    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            vpd.push_back(eqation(line[i], line[j]));
            if (vpd.back().first == INF || vpd.back().second == INF) { vpd.pop_back(); continue; }

        }
    }
    long long sizeX = maxX - minX + 1;
    long long sizeY = maxY - minY + 1;

    string t;
    for (int i = 0; i < sizeX; i++) {
        t += '.';
    }
    vector<string> v(sizeY, t);

    for (auto i : vpd) {
        int y = minX * -1 + i.first;
        int x = (i.second - maxY) * -1;
        v[x][y] = '*';
    }

    return v;
}