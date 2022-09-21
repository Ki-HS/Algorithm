#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> s, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : s)pq.push(i);
    while (pq.size() > 1) {
        if (pq.top() >= K)break;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
        answer++;
    }

    if (pq.size() == 1 && pq.top() < K)return -1;
    return answer;
}