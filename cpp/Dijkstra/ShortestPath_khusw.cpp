/*
    최단 경로 연습
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 20001

using namespace std;

int V, E, K;  // 정점 갯수, 간선 갯수, 시작 정점 번호
int dist[MAX];
int checked[MAX];
vector<pair<int, int>> adj[MAX];
int INF = 987654321;

void dijkstra(int start) {
    checked[start] = true;
    dist[start] = 0;                                                                     // 처음 시작 점은 거리가 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 새 거리값, 새 노드 번호 순으로 정의해야 max_heap 기준에 맞게 정렬됨. (기본 기준 정렬은 pair 의 first)
    // greater<int> 로 선언한 것은, 최소 힙으로 바꾸기 위함임.
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();

        if (dist[node] < node_distance)
            continue;

        for (int i = 0; i < adj[node].size(); i++) {
            // 인접 노드의 경우 0번 부터 시작해야 맞음
            int next_node = adj[node][i].first;                            // adj<pair<다음노드, 다음노드거리>> 로 정의됨
            int next_node_distance = adj[node][i].second + node_distance;  // 새 노드와의 인접 거리 + 현재 거리
            if (dist[next_node] > next_node_distance) {
                dist[next_node] = next_node_distance;
                checked[next_node] = true;
                pq.push(make_pair(next_node_distance, next_node));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}