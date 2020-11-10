/*
    AOJ BOGGLE 보글 게임
    https://algospot.com/judge/problem/read/BOGGLE
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int T, N;

string word;
string board[5];
bool visited[5][5][10];

bool search(int y, int x, int idx) {
    visited[y][x][idx] = true;

    if (board[y][x] != word[idx]) return false;
    if (idx == word.length() - 1) return true;

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((0 <= ny && ny < 5) && (0 <= nx && nx < 5)) {
            if (visited[ny][nx][idx + 1]) continue;
            if (search(ny, nx, idx + 1)) return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        for (int i = 0; i < 5; ++i) cin >> board[i];

        cin >> N;
        for (int i = 0; i < N; ++i) {
            memset(visited, 0, sizeof(visited));
            cin >> word;
            cout << word << " ";

            bool result = false;

            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (search(j, k, 0)) result = true;
                    if (result) break;
                }
                if (result) break;
            }
            if (result)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}