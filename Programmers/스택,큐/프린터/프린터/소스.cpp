#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0;
    vector<int> q;
    for (int i = 0; i < p.size(); i++) {
        q.push_back(i);
    }

    while (1) {
        if (p[0] == *max_element(p.begin(), p.end()) && q[0] == l) {
            answer++;
            break;
        }
        else if (p[0] == *max_element(p.begin(), p.end())) {
            p.erase(p.begin());
            q.erase(q.begin());
            answer++;
        }
        else {
            p.push_back(p[0]);
            q.push_back(q[0]);
            p.erase(p.begin());
            q.erase(q.begin());
        }
    }


    return answer;
}