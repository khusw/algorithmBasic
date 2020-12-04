/*
    BOJ 14502 연구소
    https://www.acmicpc.net/problem/14502
*/

#include <bits/stdc++.h>

#define MAX 8

using namespace std;

int n, m, answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int adj[MAX][MAX];
int copy_adj[MAX][MAX];
bool visited[MAX][MAX];
bool selected_wall[MAX * MAX];
vector<pair<int, int>> virus, space;
int cnt_zero;

void copy_map() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            copy_adj[i][j] = adj[i][j];
}

int count_zero() {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (copy_adj[i][j] == 0) cnt++;
    return cnt;
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (!visited[ny][nx] && copy_adj[ny][nx] == 0) {
                visited[ny][nx] = true;
                copy_adj[ny][nx] = 2;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

void spread_virus() {
    copy_map();
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 0; i < cnt_zero; ++i) {
        if (cnt == 3) break;
        if (selected_wall[i]) {
            int y = space[i].first;
            int x = space[i].second;
            copy_adj[y][x] = 1;
            cnt++;
        }
    }

    for (int i = 0; i < virus.size(); ++i) {
        int y = virus[i].first;
        int x = virus[i].second;
        bfs(y, x);
    }

    answer = max(answer, count_zero());
}

void build_wall(int idx, int wall) {
    if (wall == 3) {
        spread_virus();
        return;
    }

    for (int i = idx; i < cnt_zero; ++i) {
        if (selected_wall[i]) continue;
        selected_wall[i] = true;
        build_wall(i, wall + 1);
        selected_wall[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 0) space.push_back(make_pair(i, j));
            if (adj[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    cnt_zero = space.size();

    build_wall(0, 0);

    cout << answer;

    return 0;
}