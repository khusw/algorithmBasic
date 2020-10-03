/*
    BOJ 7576 토마토
    https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1001

using namespace std;

int M, N, answer;
int adj[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_y = y + dy[i];
            int new_x = x + dx[i];
            if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N) && adj[new_y][new_x] == 0) {
                adj[new_y][new_x] = adj[y][x] + 1;
                q.push({new_y, new_x});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (adj[i][j] == 0) {
                cout << "-1" << '\n';
                return 0;
            }

            if (answer < adj[i][j]) {
                answer = adj[i][j];
            }
        }
    }

    cout << answer - 1 << '\n';

    return 0;
}