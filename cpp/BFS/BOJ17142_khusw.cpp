/*
    BOJ 17142 연구소 3
    https://www.acmicpc.net/problem/17142
*/

#include <bits/stdc++.h>

#define MAX_N 50
#define MAX_M 10
#define INF 1e9

using namespace std;

int n, m, answer = INF, virus_cnt, empty_cnt;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int adj[MAX_N][MAX_N], copy_adj[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool selected_virus[MAX_M];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

void copy_map() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == 0 || adj[i][j] == 2) copy_adj[i][j] = -1;
            if (adj[i][j] == 1) copy_adj[i][j] = -2;
        }
    }
}

void bfs() {
    int total_time = 0, empty_space = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (!visited[ny][nx] && copy_adj[ny][nx] == -1) {
                visited[ny][nx] = true;
                copy_adj[ny][nx] = copy_adj[y][x] + 1;
                if (adj[ny][nx] == 0) {
                    empty_space++;
                    total_time = copy_adj[ny][nx];
                }
                q.push(make_pair(ny, nx));
            }
        }
    }

    if (empty_cnt == empty_space)
        answer = min(answer, total_time);
}

void spread_virus() {
    memset(visited, false, sizeof(visited));
    copy_map();

    int cnt = 0;
    for (int i = 0; i < virus_cnt; ++i) {
        if (cnt == m) break;
        if (selected_virus[i]) {
            int y = virus[i].first;
            int x = virus[i].second;
            copy_adj[y][x] = 0;
            q.push(make_pair(y, x));
            cnt++;
        }
    }

    bfs();
}

void recursion(int idx, int depth) {
    if (depth == m) {
        spread_virus();
        return;
    }

    for (int i = idx; i < virus_cnt; ++i) {
        if (selected_virus[i]) continue;
        selected_virus[i] = true;
        recursion(i, depth + 1);
        selected_virus[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 0) empty_cnt++;
            if (adj[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    virus_cnt = virus.size();

    recursion(0, 0);

    if (answer == INF)
        cout << "-1"
             << "\n";
    else
        cout << answer << "\n";

    return 0;
}