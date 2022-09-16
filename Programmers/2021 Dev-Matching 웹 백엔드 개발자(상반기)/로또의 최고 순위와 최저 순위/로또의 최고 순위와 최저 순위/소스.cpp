#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win) {
    vector<int> answer;
    int zero = 0, o = 0, x = 0;
    for (auto i : lottos) {
        if (i == 0) { zero++; continue; }
        auto iter = find(win.begin(), win.end(), i);
        if (iter != win.end())o++;
        else x++;
    }
    if (zero || o)answer.push_back(6 - (zero + o) + 1);
    else answer.push_back(6);
    if (o)answer.push_back((6 - o) + 1);
    else answer.push_back(6);
    return answer;
}