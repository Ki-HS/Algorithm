#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp1(pair<int, double> a, pair<int, double>b) {
    return a.second > b.second;
}
bool cmp2(pair<int, double> a, pair<int, double>b) {
    if (a.second == b.second)return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> v(N + 2, 0);
    map<int, int>m;
    for (int i = 0; i < stages.size(); i++) {
        m[stages[i]]++;
        for (int j = 1; j <= stages[i]; j++)v[j]++;
    }
    vector<pair<int, double>> v2;
    for (int i = 1; i <= N; i++) {
        if (v[i] == 0)v2.push_back(make_pair(i, 0));
        else v2.push_back(make_pair(i, (double)m[i] / v[i]));
    }

    sort(v2.begin(), v2.end(), cmp1);
    stable_sort(v2.begin(), v2.end(), cmp2);

    for (auto i : v2)answer.push_back(i.first);


    return answer;
}