#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int timediff(string a, string b) {
    string first_hour = "";
    first_hour = first_hour + a[0] + a[1];
    int first = stoi(first_hour) * 60;
    string first_minute = "";
    first_minute = first_minute + a[3] + a[4];
    first += stoi(first_minute);

    string second_hour = "";
    second_hour = second_hour + b[0] + b[1];
    int second = stoi(second_hour) * 60;
    string second_minute = "";
    second_minute = second_minute + b[3] + b[4];
    second += stoi(second_minute);

    return second - first;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    deque<pair<string, int>> undone;

    sort(plans.begin(), plans.end(), cmp);

    for (int i = 0; i < plans.size() - 1; i++) {
        int minus = timediff(plans[i][1], plans[i + 1][1]);
        if (minus >= stoi(plans[i][2])) {
            answer.push_back(plans[i][0]);
            int time_tmp = minus - stoi(plans[i][2]);

            while (!undone.empty()) {
                int rest_time = undone[0].second;

                if (rest_time <= time_tmp) {
                    answer.push_back(undone[0].first);
                    undone.pop_front();
                    time_tmp -= rest_time;
                }
                else {
                    undone[0].second -= time_tmp;
                    break;
                }
            }
        }
        else {
            int tmp = stoi(plans[i][2]) - minus;
            undone.push_front({ plans[i][0], tmp });
        }
    }
    answer.push_back(plans[plans.size() - 1][0]);

    while (!undone.empty()) {
        answer.push_back(undone[0].first);
        undone.pop_front();
    }

    return answer;
}