#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m;
    map<string, string> park;
    for (auto i : records) {
        stringstream sstream(i);
        string temp;
        vector<string> t;
        while (sstream >> temp)t.push_back(temp);
        if (t[2] == "IN") {
            park[t[1]] = t[0];
        }
        else {
            stringstream sstream2(park[t[1]]);
            vector<int> time1;
            vector<int> time2;
            string tmp;
            while (getline(sstream2, tmp, ':'))time1.push_back(stoi(tmp));
            stringstream sstream3(t[0]);
            while (getline(sstream3, tmp, ':'))time2.push_back(stoi(tmp));
            int pTime = (time2[0] - time1[0]) * 60 + (time2[1] - time1[1]);
            m[t[1]] += pTime;
            park.erase(t[1]);
        }
    }
    for (auto i : park) {
        stringstream sstream2(i.second);
        vector<int> time1;
        string tmp;
        while (getline(sstream2, tmp, ':'))time1.push_back(stoi(tmp));
        int pTime = (23 - time1[0]) * 60 + (59 - time1[1]);
        m[i.first] += pTime;
    }

    for (auto i : m) {
        if (i.second < fees[0])answer.push_back(fees[1]);
        else {
            answer.push_back(fees[1] + ceil(double(i.second - fees[0]) / double(fees[2])) * fees[3]);
        }
    }
    return answer;
}