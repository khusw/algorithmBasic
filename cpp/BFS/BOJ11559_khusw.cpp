/*
    BOJ 11559 Puyo Puyo
    https://www.acmicpc.net/problem/11559
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char adj[12][6];                // 인접행렬
bool visited[12][6];            // 방문여부 행렬
int labelingAdj[12][6];         // 동일한 색상의 뿌요에는 동일한 label 번호가 붙는다.
int labelingCount[12 * 6 + 1];  // label 번호가 몇개 들어있는지 파악하고, 4개 이상 있으면 지워야할게 있는것.

void resetPuyo() {
    for (int c = 0; c < 6; ++c) {
        int row_top = 11;
        for (int r = 11; r >= 0; --r) {
            if (adj[r][c] == '.') continue;
            if (row_top != r) {
                adj[row_top][c] = adj[r][c];
                adj[r][c] = '.';
            }
            --row_top;
        }
    }
}

void removePuyo(int label) {
    for (int i = 1; i <= label; ++i) {
        if (labelingCount[i] >= 4) {
            for (int y = 0; y < 12; ++y) {
                for (int x = 0; x < 6; ++x) {
                    if (labelingAdj[y][x] == i)
                        adj[y][x] = '.';
                }
            }
        }
    }
}

void bfs(int r, int c, int label) {
    char color = adj[r][c];
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = true;
    labelingAdj[r][c] = label;
    labelingCount[label]++;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (!visited[ny][nx] && adj[ny][nx] == color) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                labelingAdj[ny][nx] = label;
                labelingCount[label]++;
            }
        }
    }
}

bool canDeletePuyo(int label) {
    for (int i = 1; i <= label; ++i)
        if (labelingCount[i] >= 4) return true;

    return false;
}

int solve() {
    int label = 1;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (!visited[i][j] && adj[i][j] != '.') {
                bfs(i, j, label++);
            }
        }
    }
    return label;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> adj[i][j];

    while (1) {
        memset(visited, false, sizeof(visited));
        memset(labelingAdj, 0, sizeof(labelingAdj));
        memset(labelingCount, 0, sizeof(labelingCount));

        int label = solve();

        if (!canDeletePuyo(label)) break;

        removePuyo(label);

        resetPuyo();

        answer += 1;
    }

    cout << answer << endl;

    return 0;
}