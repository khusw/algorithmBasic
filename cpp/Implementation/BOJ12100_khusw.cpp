/*
    BOJ 12100 2048 game (easy)
    https://www.acmicpc.net/problem/12100
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, answer;
int board[20][20];

void copyBoard(int dest[20][20], int src[20][20]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dest[i][j] = src[i][j];
}

int findMaximum() {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] > cnt) cnt = board[i][j];
    return cnt;
}

void direction(int dir) {  // dir 0 : west, 1 : east, 2 : north, 3 : south
    for (int y = 0; y < n; ++y) {
        vector<int> tmp;
        for (int x = 0; x < n; ++x)
            if ((dir < 2 ? board[y][x] : board[x][y]) != 0)
                tmp.push_back((dir < 2 ? board[y][x] : board[x][y]));

        if (dir == 1 || dir == 3)
            reverse(tmp.begin(), tmp.end());

        vector<int> perm;
        for (int x = 0; x < tmp.size(); ++x) {
            if (x + 1 < tmp.size() && tmp[x] == tmp[x + 1]) {
                perm.push_back(tmp[x] * 2);
                x++;
            } else
                perm.push_back(tmp[x]);
        }
        for (int x = perm.size(); x < n; ++x)
            perm.push_back(0);

        if (dir == 1 || dir == 3)
            reverse(perm.begin(), perm.end());

        for (int x = 0; x < n; ++x)
            (dir < 2 ? board[y][x] : board[x][y]) = perm[x];
    }
}

void recursion(int idx) {
    if (idx == 5) {
        int cnt = findMaximum();
        if (cnt > answer) answer = cnt;
        return;
    }
    int copyMap[20][20];
    for (int dir = 0; dir < 4; ++dir) {
        copyBoard(copyMap, board);
        direction(dir);
        recursion(idx + 1);
        copyBoard(board, copyMap);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    recursion(0);
    cout << answer;

    return 0;
}