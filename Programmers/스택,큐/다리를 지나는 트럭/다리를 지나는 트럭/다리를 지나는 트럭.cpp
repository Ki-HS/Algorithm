#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int length, int weight, vector<int> truck) {
    int answer = 0;

    int idx = 0;
    vector<int> s;
    int w = 0;
    queue<pair<int, int>> q;
    answer = 1;
    q.push({ answer + length, truck[idx] });
    w += truck[idx];
    idx++;
    while (s.size() < truck.size()) {
        answer++;
        if (q.front().first == answer) {
            w -= q.front().second;
            s.emplace_back(q.front().second);
            q.pop();
        }
        if (w + truck[idx] <= weight) {
            q.push({ answer + length,truck[idx] });
            w += (truck[idx]);
            idx++;
        }
    }

    return answer;
}

int main() {
    cout << solution(2, 10, { 7,4,5,6 });
}