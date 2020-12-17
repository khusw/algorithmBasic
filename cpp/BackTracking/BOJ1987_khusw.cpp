/*
    BOJ 1987 Alphabet
    https://www.acmicpc.net/problem/1987
*/

#include <algorithm>
#include <iostream>

using namespace std;

int r, c, answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool alphabet[26];
bool visited[21][21];
char adj[21][21];

void dfs(int y, int x, int cnt) {
    answer = max(answer, cnt);
    visited[y][x] = true;
    alphabet[adj[y][x] - 'A'] = true;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny <= 0 || ny > r || nx <= 0 || nx > c) continue;
        if (!visited[ny][nx] && !alphabet[adj[ny][nx] - 'A']) {
            dfs(ny, nx, cnt + 1);
        }
    }

    alphabet[adj[y][x] - 'A'] = false;
    visited[y][x] = false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> r >> c;

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> adj[i][j];

    dfs(1, 1, 1);
    cout << answer;

    return 0;
}