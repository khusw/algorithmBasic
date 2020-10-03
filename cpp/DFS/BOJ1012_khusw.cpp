/*
    BOJ 1012 유기농 배추
    https://www.acmicpc.net/problem/1012
*/

#include <cstring>
#include <iostream>
#define MAX 51

using namespace std;

int T, M, N, K;
int checked[MAX][MAX];
int adj[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    checked[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int new_x = dx[k] + x;
        int new_y = dy[k] + y;
        if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N)) {
            if (adj[new_x][new_y] == 1 && !checked[new_x][new_y]) {
                dfs(new_x, new_y);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(checked, 0, sizeof(checked));
        memset(adj, 0, sizeof(adj));

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][j] == 1 && !checked[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}