/*
    BOJ 1018 체스판 다시 칠하기
    https://www.acmicpc.net/problem/1018
*/

#include <algorithm>
#include <iostream>
#define MAX 51

using namespace std;

int N, M, answer;
char adj[MAX][MAX];

int make_black_chess(int i, int j) {
    int cnt = 0;
    for (int x = i; x < i + 8; x++) {
        for (int y = j; y < j + 8; y++) {
            if (x == i || x == i + 2 || x == i + 4 || x == i + 6) {
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    if (adj[x][y] != 'B') cnt++;
                } else {
                    if (adj[x][y] != 'W') cnt++;
                }
            } else {
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    if (adj[x][y] != 'W') cnt++;
                } else {
                    if (adj[x][y] != 'B') cnt++;
                }
            }
        }
    }
    return cnt;
}

int make_white_chess(int i, int j) {
    int cnt = 0;
    for (int x = i; x < i + 8; x++) {
        for (int y = j; y < j + 8; y++) {
            if (x == i || x == i + 2 || x == i + 4 || x == i + 6) {
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    if (adj[x][y] != 'W') cnt++;
                } else {
                    if (adj[x][y] != 'B') cnt++;
                }
            } else {
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    if (adj[x][y] != 'B') cnt++;
                } else {
                    if (adj[x][y] != 'W') cnt++;
                }
            }
        }
    }
    return cnt;
}

int make_chess() {
    int total_min = 987654321;
    int white_min, black_min;
    for (int i = 0; i < N; i++) {
        if (N < i + 8) break;
        for (int j = 0; j < M; j++) {
            if (M < j + 8) break;
            white_min = make_white_chess(i, j);
            black_min = make_black_chess(i, j);
            total_min = min(total_min, min(white_min, black_min));
        }
    }
    if (total_min == 0) total_min = 1;
    return total_min;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }
    answer = make_chess();
    cout << answer;
    return 0;
}