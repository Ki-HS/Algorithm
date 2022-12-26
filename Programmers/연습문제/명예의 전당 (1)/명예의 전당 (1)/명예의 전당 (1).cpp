#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < score.size(); i++) {
        if (i < k) {
            pq.push(score[i]);
            answer.push_back(pq.top());
            continue;
        }

        if (pq.top() >= score[i]) answer.push_back(pq.top());
        else {
            pq.push(score[i]);
            pq.pop();
            answer.push_back(pq.top());
        }
    }
    return answer;
}