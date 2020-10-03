/*
    BOJ 1753 최단거리
    https://www.acmicpc.net/problem/1753
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E, K;
int INF = 987654321;
int checked[20001];
vector<pair<int, int>> adj[20001];
int dist[20001];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < distance)
            continue;

        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i].first;
            int nextDistance = distance + adj[current][i].second;

            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }

    return 0;
}