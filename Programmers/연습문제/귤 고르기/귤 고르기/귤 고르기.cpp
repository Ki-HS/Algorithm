#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int>b) {
        return a.second < b.second;
    }
};

int solution(int k, vector<int> tan) {
    int answer = 0;

    map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
    for (int i : tan)m[i]++;

    for (auto i = m.begin(); i != m.end(); i++) {
        pq.push(make_pair(i->first, i->second));
    }
    int i = 0;
    while (!pq.empty()) {
        k -= pq.top().second;
        pq.pop();
        i++;
        if (k <= 0)return i;
    }

    return i;
}

int main() {
    vector<int> t = { 1, 3, 2, 5, 4, 5, 2, 3 };
    cout << solution(4, t);
}