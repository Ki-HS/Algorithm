#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);

    priority_queue<int, vector<int>> max;
    priority_queue<int, vector<int>,greater<int>> min;
    auto tMax = max;
    auto tMin = min;

    map<int, int> m;
    for (auto op : operations) {
        if (op[0] == 'D') {
            if (m.empty()) continue;
            if (op[2] == '-')
            {
                m.erase(min.top());
                    min.pop();
                if (m.empty())
                 {
                    min = tMin;
                    max = tMax;
                }

            }
            else
            {
                m.erase(max.top());
                    max.pop();
                if (m.empty())
                 {
                    min = tMin;
                    max = tMax;
                }
            }
            continue;
        }
        string str = op.substr(2, op.size());
        int num = stoi(str);
        m[num];
        min.push(num);
        max.push(num);
    }
    
    if (!m.empty())
    {
        answer[0] = max.top();
        answer[1] = min.top();
    }
        return answer;

}

int main() {
    cout<<solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" })[0];
}