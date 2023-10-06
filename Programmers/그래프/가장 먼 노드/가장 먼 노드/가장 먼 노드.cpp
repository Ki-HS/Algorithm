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
        int cost = -pq.top().first; // �켱����ť�� �������� �����̱� ����
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
ó������ �÷��̵� ������ ��µ� ��尡 ���ٺ��� �ð� �ʰ��� ����. �켱������ �̿��� ���ͽ�Ʈ�� ����ߴ��� �ذ��� �� �־���.
*/