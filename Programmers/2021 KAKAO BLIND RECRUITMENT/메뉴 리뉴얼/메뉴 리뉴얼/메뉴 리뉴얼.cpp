#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<string, int>> m;
bool sorting1(pair<string, int> a, pair<string, int> b) {
    return a.first.size() < b.first.size();
}

bool sorting2(pair<string, int> a, pair<string, int> b) {
    if (a.first.size() == b.first.size()) {
        return a.second > b.second;
    }
    else return a.first.size() < b.first.size();
}

void menu(string order, vector<char> comb, int r, int idx, int deep) {
    if (!r) {
        string temp = "";
        for (int i = 0; i < comb.size(); i++) {
            temp += comb[i];
        }

        for (int i = 0; i < m.size(); i++) {
            if (m[i].first == temp) {
                m[i].second++;
                return;
            }
        }
        m.push_back(make_pair(temp, 1));
        return;
    }
    else if (deep == order.size()) return;
    comb[idx] = order[deep];
    menu(order, comb, r - 1, idx + 1, deep + 1);
    menu(order, comb, r, idx, deep + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int j = 0; j < course.size(); j++) {
        for (int i = 0; i < orders.size(); i++) {
            vector<char> temp(course[j]);
            menu(orders[i], temp, course[j], 0, 0);
        }
    }

    sort(m.begin(), m.end(), sorting1);
    stable_sort(m.begin(), m.end(), sorting2);

    int max = m[0].second;
    if (m[0].second > 1)answer.push_back(m[0].first);
    for (int i = 1; i < m.size(); i++) {
        if (m[i - 1].first.size() != m[i].first.size() && m[i].second > 1)
        {
            answer.push_back(m[i].first);
            max = m[i].second;
            continue;
        }
        if (max == m[i].second && m[i].second > 1)answer.push_back(m[i].first);
    }

    sort(answer.begin(), answer.end());

    return answer;
}