/*
    BOJ 1260 (DFS 와 BFS)
    https://www.acmicpc.net/problem/1260
*/

#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
int checked[1001];
vector<int> adj[1001];

void bfs(int node) {
    queue<int> q;
    checked[node] = true;
    q.push(node);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        sort(adj[x].begin(), adj[x].end());
        for (int i = 0; i < adj[x].size(); i++) {
            int y = adj[x][i];
            if (!checked[y]) {
                q.push(y);
                checked[y] = true;
            }
        }
    }
}

void dfs(int node) {
    if (checked[node])
        return;
    checked[node] = true;
    cout << node << ' ';
    sort(adj[node].begin(), adj[node].end());
    for (int i = 0; i < adj[node].size(); i++) {
        int y = adj[node][i];
        dfs(y);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(V);
    memset(checked, 0, sizeof(checked));
    cout << '\n';
    bfs(V);

    return 0;
}