//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#define inf 9999999
//using namespace std;
//
//vector<pair<int, int>> nodes[201];
//vector<int> dist(201,inf );
//
//void dijkstra(int start) {
//    priority_queue<pair<int, int>> pq;
//
//    pq.push({ 0, start });
//    dist[start] = 0;
//
//    while (!pq.empty()) {
//        int cost = -pq.top().first; // 우선순위큐는 내림차순 정렬이기 때문
//        int here = pq.top().second;
//        pq.pop();
//
//        if (dist[here] < cost) continue;
//
//        for (int i = 0; i < nodes[here].size(); i++) {
//            int via_cost = cost + nodes[here][i].first;
//
//            if (via_cost < dist[nodes[here][i].second]) {
//                dist[nodes[here][i].second] = via_cost;
//                pq.push({ -via_cost, nodes[here][i].second });
//            }
//        }
//    }
//}
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//    int answer = 0;
//    vector<int> temp(201, inf);
//
//    for (vector<int> v : fares) {
//        nodes[v[0]].push_back({ v[2],v[1] });
//        nodes[v[1]].push_back({ v[2],v[0] });
//    }
//
//    dijkstra(s);
//    int routeA = dist[a];
//    int routeB = dist[b];
//    dist = temp;
//    dijkstra(a);
//    routeA += dist[b];
//
//    dist = temp;
//    dijkstra(b);
//    routeB += dist[a];
//
//    return routeA < routeB ? routeA : routeB;
//}
//
//int main() {
//    solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}} );
//}

#include <string>
#include <vector>

using namespace std;

#define INF 20000000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, INF)); 

    for (int i = 0; i < fares.size(); ++i) {
        v[fares[i][0]][fares[i][1]] = v[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n; ++i)
        v[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (v[i][j] > v[i][k] + v[k][j])
                    v[i][j] = v[i][k] + v[k][j];

    for (int i = 1; i <= n; ++i)
        if (answer > v[s][i] + v[i][a] + v[i][b])
            answer = v[s][i] + v[i][a] + v[i][b];

    return answer;
}

/*
    다익스트라를 사용해서 문제풀이를 할때는 출발 지점에 따라 계산을 진행했어야 했는데
    플로이드를 사용했을 때는 저장할 필요가 없어서 조금 더 빨리 진행할 수 있었다.
*/