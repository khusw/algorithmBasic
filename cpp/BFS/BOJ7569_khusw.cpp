/*
    BOJ 7569 토마토 2
    https://www.acmicpc.net/problem/7569
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N, H, cnt;
int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};
int adj[101][101][101];
queue<pair<pair<int, int>, int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if ((0 <= ny && ny < N) && (0 <= nx && nx < M) && (0 <= nz && nz < H) && adj[ny][nx][nz] == 0) {
                adj[ny][nx][nz] = adj[y][x][z] + 1;
                q.push(make_pair(make_pair(ny, nx), nz));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> adj[j][k][i];
                if (adj[j][k][i] == 1) {
                    q.push(make_pair(make_pair(j, k), i));
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (adj[j][k][i] == 0) {
                    cout << "-1" << '\n';
                    return 0;
                }

                if (cnt < adj[j][k][i]) {
                    cnt = adj[j][k][i];
                }
            }
        }
    }

    cout << cnt - 1 << '\n';

    return 0;
}