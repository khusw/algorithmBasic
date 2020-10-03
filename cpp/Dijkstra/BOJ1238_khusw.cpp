/*
    BOJ 1238 파티
    https://www.acmicpc.net/problem/1238
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 10001
#define INF 987654321

using namespace std;

int N, M, X, answer;
vector<pair<int, int>> adj[MAX];

int dijkstra(int start, int end) {
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i].first;
            int next_node_distance = node_distance + adj[node][i].second;

            if (dist[next_node] > next_node_distance) {
                dist[next_node] = next_node_distance;
                pq.push(make_pair(next_node_distance, next_node));
            }
        }
    }
    return dist.at(end);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        adj[x].push_back(make_pair(y, dist));
    }

    for (int i = 1; i <= N; i++) {
        int temp = 0;
        temp = dijkstra(i, X) + dijkstra(X, i);
        if (answer < temp) {
            answer = temp;
        }
    }

    cout << answer;

    return 0;
}