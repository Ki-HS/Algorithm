#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int>b) {
        return a.second < b.second;
    }
};

bool map_cmp(pair<string, int> a, pair<string, int>b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m;
    map < string, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>> mpq;

    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        mpq[genres[i]].push({ i, plays[i] });
    }

    vector<pair<string, int>> v;

    for (auto i = m.begin(); i != m.end(); i++)
        v.push_back({ i->first,i->second });

    sort(v.begin(), v.end(), map_cmp);
    for (pair<string, int> p : v) {
        int i = 0;
        while (mpq[p.first].size() && i != 2) {
            answer.push_back(mpq[p.first].top().first);
            mpq[p.first].pop();
            i++;
        }
    }

    return answer;
}