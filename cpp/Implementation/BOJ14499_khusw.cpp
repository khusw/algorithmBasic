/*
    BOJ 14499 주사위 굴리기
    https://www.acmicpc.net/problem/14499
*/

#include <bits/stdc++.h>

#define endl "\n"
#define MAX_N 21
#define MAX_K 1001

using namespace std;

int n, m, k;
int adj[MAX_N][MAX_N];
int order[MAX_K];
int dx[4] = {0, 0, -1, 1};  // 동, 서, 북, 남 순서
int dy[4] = {1, -1, 0, 0};
vector<int> dice(6, 0);  // 위, 아래, 오른쪽, 왼쪽, 앞, 뒷 순서

void turnDice(int dir) {
    vector<int> copyDice = dice;

    if (dir == 1) {
        dice[0] = copyDice[3];
        dice[1] = copyDice[2];
        dice[2] = copyDice[0];
        dice[3] = copyDice[1];
    } else if (dir == 2) {
        dice[0] = copyDice[2];
        dice[1] = copyDice[3];
        dice[2] = copyDice[1];
        dice[3] = copyDice[0];
    } else if (dir == 3) {
        dice[0] = copyDice[4];
        dice[1] = copyDice[5];
        dice[4] = copyDice[1];
        dice[5] = copyDice[0];
    } else if (dir == 4) {
        dice[0] = copyDice[5];
        dice[1] = copyDice[4];
        dice[4] = copyDice[0];
        dice[5] = copyDice[1];
    }
}

void solve(int x, int y) {
    int orderNum = 0;
    for (int i = 0; i < k; ++i) {
        orderNum = order[i];
        int nx = x + dx[orderNum - 1];
        int ny = y + dy[orderNum - 1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        turnDice(orderNum);
        if (adj[nx][ny] == 0) {
            adj[nx][ny] = dice[1];
        } else {
            dice[1] = adj[nx][ny];
            adj[nx][ny] = 0;
        }
        x = nx;
        y = ny;
        cout << dice[0] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x, y;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> adj[i][j];

    for (int i = 0; i < k; ++i) cin >> order[i];

    solve(x, y);

    return 0;
}