/*
    BOJ 9376 탈옥
    https://www.acmicpc.net/problem/9376
*/
#include <cstring>
#include <deque>
#include <iostream>

#define MAX 102

using namespace std;

int t, h, w;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char map[MAX][MAX];
int dist[MAX][MAX][3];

void bfs(deque<pair<int, int>>& q) {
    q.push_back({0, 0});
    for (int k = 0; k < 3; ++k) {
        int sy = q.back().first, sx = q.back().second;
        q.pop_back();
        deque<pair<int, int>> nq;
        nq.push_back({sy, sx});
        dist[sy][sx][k] = 0;
        while (!nq.empty()) {
            int y = nq.front().first, x = nq.front().second;
            nq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || ny > h + 1 || nx < 0 || nx > w + 1) continue;
                if (dist[ny][nx][k] >= 0 || map[ny][nx] == '*') continue;
                if (map[ny][nx] == '.') {
                    dist[ny][nx][k] = dist[y][x][k];
                    nq.push_front({ny, nx});
                } else if (map[ny][nx] == '#') {
                    dist[ny][nx][k] = dist[y][x][k] + 1;
                    nq.push_back({ny, nx});
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> h >> w;

        memset(dist, -1, sizeof(dist));
        deque<pair<int, int>> q;

        for (int i = 0; i < h + 2; ++i) {
            for (int j = 0; j < w + 2; ++j) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
                    map[i][j] = '.';
                else
                    cin >> map[i][j];

                if (map[i][j] == '$') {
                    map[i][j] = '.';
                    q.push_back({i, j});
                }
            }
        }

        bfs(q);

        int answer = 987654321;
        for (int i = 0; i < h + 2; ++i) {
            for (int j = 0; j < w + 2; ++j) {
                if (map[i][j] == '*') continue;
                int sum = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
                if (map[i][j] == '#') sum -= 2;
                if (answer > sum) answer = sum;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}