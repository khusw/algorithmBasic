/*
    BOJ 11725 Find Parent Node
    https://www.acmicpc.net/problem/11725
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = cur;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, false);
    parent.resize(n + 1);

    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << endl;
    }

    return 0;
}