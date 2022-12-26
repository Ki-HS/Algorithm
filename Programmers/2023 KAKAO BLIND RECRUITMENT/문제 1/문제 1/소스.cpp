#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> exp;
    stringstream ss(today);
    string temp;
    vector<int>today_date;
    while (getline(ss, temp, '.'))today_date.push_back(stoi(temp));

    for (auto i : terms) {
        stringstream sstream(i);
        string t;
        vector<string>v;
        while (sstream >> t)v.push_back(t);
        exp[v[0]] = stoi(v[1]);
    }

    int idx = 1;
    for (auto i : privacies) {
        stringstream sstream(i);
        string t;
        vector<string>v;
        while (sstream >> t)v.push_back(t);

        stringstream sstream2(v[0]);
        vector<int>date;
        while (getline(sstream2, t, '.'))date.push_back(stoi(t));
        
        if (date[1] + exp[v[1]]>12&&(date[1] + exp[v[1]])%12!=0)
        date[0] += (date[1] + exp[v[1]]) / 12;
        else if(date[1] + exp[v[1]]>12)date[0] += (date[1] + exp[v[1]]) / 12-1;
        date[1] = (date[1] + exp[v[1]]) % 12;
        if (date[1] == 0)date[1] = 12;
        if (date[0] < today_date[0] || (date[0] == today_date[0] && date[1] < today_date[1]) || (date[0] == today_date[0] && date[1] == today_date[1] && date[2] <= today_date[2])) {
            answer.push_back(idx);
        }
        idx++;
    }
    return answer;
}

int main() {
    string today = "2022.12.19";
    vector<string> a = { "A 6","B 13", "C 1", "D 25"};
    vector<string> b = { "2021.06.02 A", "2021.09.19 C","2021.11.19 B", "2022.11.19 C" };
    solution(today, a, b);
}