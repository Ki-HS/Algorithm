#include <string>
#include <vector>
#include <queue>
#define inf 99999999

using namespace std;

vector<pair<int, int>> nodes[20001];
vector<int> dist(20001, inf);

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first; // 우선순위큐는 내림차순 정렬이기 때문
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < nodes[here].size(); i++) {
            int via_cost = cost + nodes[here][i].first;

            if (via_cost < dist[nodes[here][i].second]) {
                dist[nodes[here][i].second] = via_cost;
                pq.push({ -via_cost, nodes[here][i].second });
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (vector<int> v : edge) {
        nodes[v[0]].push_back({ 1,v[1] });
        nodes[v[1]].push_back({ 1,v[0] });
    }

    dijkstra(1);

    int max = 0;
    vector<int> ans;

    for (int i = 2; i <= n; i++) {
        if (dist[i] != inf && dist[i] > max) {
            max = dist[i];
            ans.clear();
            ans.push_back(i);
        }
        else if (dist[i] != inf && dist[i] == max) ans.push_back(i);
    }

    return ans.size();
}

/*
처음에는 플로이드 워셜을 썼는데 노드가 많다보니 시간 초과가 났다. 우선순위를 이용한 다익스트라를 사용했더니 해결할 수 있었다.
*/