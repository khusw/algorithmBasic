/*
    BOJ 11438 LCA 2
    https://www.acmicpc.net/problem/11438
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_N 100001
#define MAX 18  // 반올림 log(2, 100000)

using namespace std;

int n, m;
int parent[MAX_N][MAX];  // parent[i][k] : i의 2^k 번째 부모
int depth[MAX_N];        // 트리에서의 깊이
vector<int> adj[MAX_N];  // 그래프의 인접행렬

void make_tree(int cur) {
    for (int next : adj[cur]) {
        if (depth[next] == -1) {
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            make_tree(next);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    fill(depth, depth + n, -1);
    depth[0] = 0;
    make_tree(0);

    for (int j = 0; j < MAX - 1; ++j)
        for (int i = 1; i < n; ++i)
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; diff; ++j) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if (u != v) {
            for (int j = MAX - 1; j >= 0; --j) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }

        cout << u + 1 << "\n";
    }

    return 0;
}