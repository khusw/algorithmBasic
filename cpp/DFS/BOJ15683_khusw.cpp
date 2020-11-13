/*
    BOJ 15683 감시
    https://www.acmicpc.net/problem/15683
*/

#include <bits/stdc++.h>

#define endl "\n"
#define INF 987654321

using namespace std;

int n, m, cntMin = INF;
int board[8][8];
vector<pair<pair<int, int>, int>> cameraPos;  // y, x, camera number
const int dirType[5] = {4, 2, 4, 4, 1};       // direction type

void copyBoard(int dest[8][8], int src[8][8]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dest[i][j] = src[i][j];
}

int cntBlindSpot() {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == 0) cnt++;
    return cnt;
}

void direction(int y, int x, int dir) {
    dir %= 4;        // when dir >= 4
    if (dir == 0) {  // E
        for (int c = x + 1; c < m; ++c) {
            if (board[y][c] == 6) break;  // wall
            board[y][c] = -1;
        }
    } else if (dir == 1) {  // N
        for (int r = y - 1; r >= 0; --r) {
            if (board[r][x] == 6) break;
            board[r][x] = -1;
        }
    } else if (dir == 2) {  // W
        for (int c = x - 1; c >= 0; --c) {
            if (board[y][c] == 6) break;
            board[y][c] = -1;
        }
    } else if (dir == 3) {  // S
        for (int r = y + 1; r < n; ++r) {
            if (board[r][x] == 6) break;
            board[r][x] = -1;
        }
    }
}

void dfs(int idx) {
    if (idx == cameraPos.size()) {
        int cnt = cntBlindSpot();
        if (cntMin > cnt) cntMin = cnt;
        return;
    }
    int cpyBoard[8][8];
    int y = cameraPos[idx].first.first, x = cameraPos[idx].first.second, camera = cameraPos[idx].second;
    for (int dir = 0; dir < dirType[camera - 1]; ++dir) {
        copyBoard(cpyBoard, board);  // back up
        if (camera == 1) {           // one direction
            direction(y, x, dir);
        } else if (camera == 2) {  // 180 degree direction
            direction(y, x, dir);
            direction(y, x, dir + 2);
        } else if (camera == 3) {  // 90 degree direction
            direction(y, x, dir);
            direction(y, x, dir + 1);
        } else if (camera == 4) {  // three direction
            direction(y, x, dir);
            direction(y, x, dir + 1);
            direction(y, x, dir + 2);
        } else if (camera == 5) {  // four direction
            direction(y, x, dir);
            direction(y, x, dir + 1);
            direction(y, x, dir + 2);
            direction(y, x, dir + 3);
        }
        dfs(idx + 1);
        copyBoard(board, cpyBoard);  // back tracking
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) {
                cameraPos.push_back(make_pair(make_pair(i, j), board[i][j]));
            }
        }
    }

    dfs(0);
    cout << cntMin << endl;

    return 0;
}