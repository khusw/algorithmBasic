/*
    BOJ 1389 케빈 베이컨 6단계 법칙
    https://www.acmicpc.net/problem/1389
*/

#include <bits/stdc++.h>

#define MAX 100

using namespace std;

int N, M;
int adj[MAX][MAX];

int minimum() {
    int result = 987654321;
    int idx = 1;
    for (int i = 1; i <= N; ++i) {
        int tmp = 0;
        for (int j = 1; j <= N; ++j) {
            tmp += adj[i][j];
        }
        if (result > tmp) {
            result = tmp;
            idx = i;
        }
    }
    return idx;
}

void floydWarshall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++k) {
            for (int j = 1; j <= N; ++j) {
                if (i == j)
                    continue;
                else if (adj[i][k] != 0 && adj[k][j] != 0) {
                    if (adj[i][j] == 0)
                        adj[i][j] = adj[i][k] + adj[k][j];
                    else
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1, adj[b][a] = 1;
    }

    floydWarshall();
    cout << minimum() << "\n";

    return 0;
}