/*
    BOJ 16234 인구 이동
    https://www.acmicpc.net/problem/16234
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 52
#define INF 987654321

using namespace std;

int N, L, R, answer, cnt, sum;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> vec;

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i], diff = abs(map[ny][nx] - map[y][x]);
            if (ny < 0 || ny > N + 1 || nx < 0 || nx > N + 1) continue;
            if (L <= diff && diff <= R && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                sum += map[ny][nx];
                cnt++;
                vec.push_back({ny, nx});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L >> R;

    memset(map, INF, sizeof(map));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> map[i][j];

    while (1) {
        bool flag = false;
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (!visited[i][j]) {
                    sum = map[i][j];
                    cnt = 1;
                    vec.clear();
                    vec.push_back({i, j});
                    bfs(i, j);
                    if (cnt >= 2) {
                        for (int i = 0; i < vec.size(); ++i) {
                            map[vec[i].first][vec[i].second] = sum / cnt;
                            flag = true;
                        }
                    }
                }
            }
        }

        if (flag)
            answer++;
        else
            break;
    }

    cout << answer;

    return 0;
}