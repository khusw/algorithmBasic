/*
    BOJ 1916 최소 비용 구하기
    https://www.acmicpc.net/problem/1916
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1001

using namespace std;

int checked[MAX];
vector<pair<int, int>> adj[MAX];
int dist[MAX];
int N, M, S, E;
int INF = 987654321;

void dijkstra(int start) {
    dist[start] = 0;
    checked[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();

        if (dist[node] < node_distance)
            continue;

        for (int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i].first;
            int next_node_distance = adj[node][i].second + node_distance;
            if (next_node_distance < dist[next_node]) {
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

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    cin >> S >> E;

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dijkstra(S);

    if (dist[E] != INF)
        cout << dist[E];

    return 0;
}