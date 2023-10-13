#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<string, pair<string, int>> m;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = { referral[i],0 };
    }

    for (int i = 0; i < seller.size(); i++) {
        string cur = seller[i];
        int t = amount[i] * 100;
        while (cur != "-") {
            if (t / 10 < 1) {
                m[cur].second += t;
                break;
            }
            m[cur].second += ceil((double)t * 0.9);
            t /= 10;
            cur = m[cur].first;
        }
    }

    for (auto e : enroll) {
        answer.push_back(m[e].second);
    }

    return answer;
}