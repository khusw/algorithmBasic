/*
    BOJ 4803 Tree
    https://www.acmicpc.net/problem/4803
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

int n, m;

int cntOfVerticies(vector<vector<int>>& adj, vector<bool>& visited, int node) {
    int cnt = 1;
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (!visited[next]) cnt += cntOfVerticies(adj, visited, next);
    }

    return cnt;
}

int cntOfEdges(vector<vector<int>>& adj, vector<bool>& passed, int node) {
    int cnt = adj[node].size();
    passed[node] = true;

    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (!passed[next]) cnt += cntOfEdges(adj, passed, next);
    }

    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 0;
    while (1) {
        int cnt = 0;
        tc++;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<vector<int>> adj;
        vector<bool> visited, passed;

        adj.resize(n + 1);
        visited.resize(n + 1, false);
        passed.resize(n + 1, false);

        int u, v;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int v = cntOfVerticies(adj, visited, i);
                int e = cntOfEdges(adj, passed, i);
                if (v - 1 == e / 2) cnt++;
            }
        }

        if (cnt == 0) {
            cout << "Case " << tc << ": No trees." << endl;
        } else if (cnt == 1) {
            cout << "Case " << tc << ": There is one tree." << endl;
        } else if (cnt > 1) {
            cout << "Case " << tc << ": A forest of " << cnt << " trees." << endl;
        }
    }

    return 0;
}