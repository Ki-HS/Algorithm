#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<long long, vector<long long>> pq;
    for (auto w : works)pq.push(w);

    while (n) {
        int temp = pq.top() - 1;

        if (temp) pq.push(temp);
        if (pq.empty())break;
        pq.pop();

        n--;
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}