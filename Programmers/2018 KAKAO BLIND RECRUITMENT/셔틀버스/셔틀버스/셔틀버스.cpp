#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(string time, string std) {
    return time <= std;
}

string clock(string time, int t) {
    string hour = time.substr(0, 2);
    string minute = time.substr(3, time.size());

    int nM = stoi(minute);
    int nH = stoi(hour);
    if (t < 0 && !nM) {
        nH--;
        nM = 59;
    }
    else {
        nH += (nM + t) / 60;
        nM = (nM + t) % 60;
    }

    string val = "";
    val += nH < 10 ? "0" + to_string(nH) : to_string(nH);
    val += ":";
    val += nM < 10 ? "0" + to_string(nM) : to_string(nM);

    return val;
}

map<string, vector<string>> m;
string solution(int n, int t, int max, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(), timetable.end(), less<string>());

    string last = clock("09:00", (n - 1) * t);

    for (auto time : timetable) {
        string cur = "09:00";
        for (int i = 0; i < n; i++) {
            if (i)cur = clock(cur, t);
            if (m[cur].size() == max) continue;

            if (cmp(time, cur)) { m[cur].push_back(time); break; }
        }
    }


    if (m[last].size()) {
        vector<string> v = m[last];
        if (m[last].size() < max) {
            return last;
        }
        else {
            answer = clock(v.back(), -1);
        }
    }
    else {
        answer = last;
    }

    return answer;
}

int main() {
    cout << solution(2, 10, 3, { "09:00", "09:00", "09:00", "09:00" });
}