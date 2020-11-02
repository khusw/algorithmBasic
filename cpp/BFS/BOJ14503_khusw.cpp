/*
    BOJ 14503 로봇 청소기
    https://www.acmicpc.net/problem/14503
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

typedef struct {
    int y, x;
} Dir;

Dir moveDir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, cnt;
int adj[MAX][MAX];

void bfs(int r, int c, int d) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, d});

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second;

        if (adj[y][x] == 0) {
            adj[y][x] = 2;
            cnt++;
        }

        q.pop();

        bool isBack = false;
        for (int i = 0; i < 4; ++i) {
            int newDir = (d + (3 - i)) % 4;
            int ny = y + moveDir[newDir].y;
            int nx = x + moveDir[newDir].x;

            if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
                if (!adj[ny][nx]) {
                    q.push({{ny, nx}, newDir});
                    isBack = true;
                    break;
                }
            }
        }

        if (!isBack) {
            int ny = y - moveDir[d].y;
            int nx = x - moveDir[d].x;

            if ((0 <= nx && nx < m) && (0 <= ny && ny < n) && (adj[ny][nx] != 1))
                q.push({{ny, nx}, d});
            else
                break;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> adj[i][j];

    bfs(r, c, d);

    cout << cnt << "\n";

    return 0;
}