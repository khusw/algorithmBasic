/*
    BOJ 14500 테트로미노
    https://www.acmicpc.net/problem/14500
*/

#include <bits/stdc++.h>

#define endl "\n"
#define MAX 501

using namespace std;

int n, m, answer;
int dx[4] = {0, 0, 1, -1};  // x 는 행, y 는 열임.
int dy[4] = {-1, 1, 0, 0};
int adj[MAX][MAX];
bool visited[MAX][MAX];

// find only "ㅜ" shape (because other shape can find in DFS, but this shape can't find in DFS, Also other shape length is 4 but "ㅜ" shape length is 3)
void findShape(int x, int y) {
    int sum = 0;

    // ㅜ shape
    if (x >= 1 && x + 1 <= n && y >= 1 && y + 2 <= m) {
        sum = adj[x][y] + adj[x][y + 1] + adj[x][y + 2] + adj[x + 1][y + 1];
        answer = max(answer, sum);
    }

    // ㅏ shape
    if (x >= 1 && x + 2 <= n && y >= 1 && y + 1 <= m) {
        sum = adj[x][y] + adj[x + 1][y] + adj[x + 2][y] + adj[x + 1][y + 1];
        answer = max(answer, sum);
    }

    // ㅓ shape
    if (x >= 1 && x + 2 <= n && y >= 1 && y + 1 <= m) {
        sum = adj[x + 1][y] + adj[x][y + 1] + adj[x + 1][y + 1] + adj[x + 2][y + 1];
        answer = max(answer, sum);
    }

    // ㅗ shape
    if (x >= 1 && x + 1 <= n && y >= 1 && y + 2 <= m) {
        sum = adj[x][y + 1] + adj[x + 1][y] + adj[x + 1][y + 1] + adj[x + 1][y + 2];
        answer = max(answer, sum);
    }
}

void dfs(int x, int y, int sum, int length) {
    if (length >= 4) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, sum + adj[nx][ny], length + 1);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> adj[i][j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            visited[i][j] = true;
            dfs(i, j, adj[i][j], 1);
            visited[i][j] = false;
            findShape(i, j);
        }
    }

    cout << answer << endl;

    return 0;
}