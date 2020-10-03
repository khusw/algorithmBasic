/*
    BOJ 2178 미로 탐색
    https://www.acmicpc.net/problem/2178
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
string adj[101];
int sum[101][101];
int checked[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    checked[i][j] = true;
    sum[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if ((0 <= newX && newX < N) && (0 <= newY && newY < M)) {
                if (adj[newX][newY] == '1' && !checked[newX][newY]) {
                    checked[newX][newY] = true;
                    q.push({newX, newY});
                    sum[newX][newY] = sum[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> adj[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (adj[i][j] == '1' && !checked[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << sum[N - 1][M - 1];

    return 0;
}
