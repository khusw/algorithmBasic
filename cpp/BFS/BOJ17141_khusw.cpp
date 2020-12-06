/*
    BOJ 17141 연구소 2
    https://www.acmicpc.net/problem/17141
*/

#include <bits/stdc++.h>

#define MAX 50
#define INF 987654321

using namespace std;

int n, m, cnt_virus, answer = INF;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int adj[MAX][MAX], copy_adj[MAX][MAX];
bool visited[MAX][MAX];
bool selected_virus[MAX * MAX];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
vector<int> vec;

int cnt_max_time() {
    int cnt = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (copy_adj[i][j] == -1) return -1;
            cnt = max(cnt, copy_adj[i][j]);
        }
    }
    return cnt;
}

void copy_map() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == 0 || adj[i][j] == 2) copy_adj[i][j] = -1;
            if (adj[i][j] == 1) copy_adj[i][j] = -2;
        }
    }
}

void bfs() {
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
                q.push(make_pair(ny, nx));
                copy_adj[ny][nx] = copy_adj[y][x] + 1;
            }
        }
    }
}

void spread_virus() {
    copy_map();
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 0; i < cnt_virus; ++i) {
        if (cnt == m) break;
        if (selected_virus[i]) {
            int y = virus[i].first;
            int x = virus[i].second;
            q.push(make_pair(y, x));
            copy_adj[y][x] = 0;
            cnt++;
        }
    }

    bfs();

    int num = cnt_max_time();
    vec.push_back(num);
}

void recursion(int idx, int depth) {
    if (depth == m) {
        spread_virus();
        return;
    }

    for (int i = idx; i < cnt_virus; ++i) {
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
            if (adj[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    cnt_virus = virus.size();

    recursion(0, 0);

    bool flag = false;
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] != -1) flag = true;

    if (flag) {
        for (int i = 0; i < vec.size(); ++i)
            if (vec[i] != -1)
                answer = min(answer, vec[i]);
        cout << answer << "\n";
    } else
        cout << -1 << "\n";

    return 0;
}