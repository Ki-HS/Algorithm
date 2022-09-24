#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

bool sort1(vector<int> a, vector<int>b) {
    return a.size() < b.size();
}
int nonDup(vector<int> tar, vector<int>ans) {
    map<int, int> m;
    for (auto i : tar) {
        m[i]++;
    }
    for (auto i : ans) {
        m.erase(i);
    }
    return m.begin()->first;
}

vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1, s.size() - 2);
    bool status = false;
    vector<vector<int>>v;
    int c;
    stringstream ss1(s);
    string t1;
    vector<string> temp;
    while (getline(ss1, t1, '}')) {
        temp.push_back(t1);
    }
    for (int i = 0; i < temp.size(); i++) {
        if (i == 0) {
            temp[i] = temp[i].substr(1, temp[i].size());
        }
        else {
            temp[i] = temp[i].substr(2, temp[i].size());
        }
        stringstream ss2(temp[i]);
        string t2;
        vector<int>v1;
        while (getline(ss2, t2, ',')) {
            v1.push_back(stoi(t2));
        }
        v.push_back(v1);
    }

    sort(v.begin(), v.end(), sort1);
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            answer.push_back(v[i][0]);
            continue;
        }
        answer.push_back(nonDup(v[i], answer));
    }
    return answer;
}