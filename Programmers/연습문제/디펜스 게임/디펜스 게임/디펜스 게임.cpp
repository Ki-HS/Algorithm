#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    int sum = 0;
    for (int i = 0; i < enemy.size(); i++) {
        int e = enemy[i];
        pq.push(e);
        if (pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }
        if (sum > n)return i;
    }
    return enemy.size();
}