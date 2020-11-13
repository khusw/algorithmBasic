/*
    BOJ 18808 스티커 붙이기
    https://www.acmicpc.net/problem/18808
*/
#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, m, k, r, c;  // board y, board x, number of sticker, sticker y, sticker x
int nr, nc;         // new y, new x (turn direction)
int board[40][40];
vector<vector<int>> copySticker;

int cntStickerArea() {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == 1) cnt++;
    return cnt;
}

void turn(int degree, vector<vector<int>>& sticker) {
    if (degree == 90) {
        nr = c;
        nc = r;
        vector<vector<int>> tmp(c, vector<int>(r, 0));
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                tmp[i][j] = copySticker[r - 1 - j][i];
            }
        }
        sticker.clear();
        sticker = tmp;
    } else if (degree == 180) {
        nr = r;
        nc = c;
        vector<vector<int>> tmp(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                tmp[i][j] = copySticker[r - 1 - i][c - 1 - j];
            }
        }
        sticker.clear();
        sticker = tmp;
    } else if (degree == 270) {
        nr = c;
        nc = r;
        vector<vector<int>> tmp(c, vector<int>(r, 0));
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                tmp[i][j] = copySticker[j][c - 1 - i];
            }
        }
        sticker.clear();
        sticker = tmp;
    }
}

bool isFit(int y, int x, vector<vector<int>>& sticker) {
    for (int i = y; i < y + nr; ++i) {
        for (int j = x; j < x + nc; ++j) {
            if (i < 0 || i >= n || j < 0 || j >= m) return false;
            if (board[i][j] == 1 && sticker[i - y][j - x] == 1) return false;
        }
    }

    for (int i = y; i < y + nr; ++i) {
        for (int j = x; j < x + nc; ++j) {
            if (board[i][j] == 0 && sticker[i - y][j - x] == 1) board[i][j] = sticker[i - y][j - x];
        }
    }
    return true;
}

void search(vector<vector<int>>& sticker, int degree) {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isFit(i, j, sticker)) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) {
        degree += 90;
        if (degree >= 360) return;
        turn(degree, sticker);
        search(sticker, degree);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> r >> c;
        nr = r;
        nc = c;
        vector<vector<int>> sticker(r, vector<int>(c, 0));
        for (int y = 0; y < r; ++y)
            for (int x = 0; x < c; ++x)
                cin >> sticker[y][x];
        copySticker = sticker;
        search(sticker, 0);
    }

    cout << cntStickerArea() << endl;

    return 0;
}