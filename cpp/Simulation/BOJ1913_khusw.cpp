/*
    BOJ 1913 달팽이
    https://www.acmicpc.net/problem/1913
*/

#include <iostream>
#define MAX 1000

using namespace std;

int N, pos;
long adj[MAX][MAX];

void print_adj() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}

pair<int, int> find_pos(int pos) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] == pos) {
                return make_pair(i + 1, j + 1);
            }
        }
    }
}

void make_snail(int N) {
    int left_limit = 0, top_limit = 0;
    int right_limit = N - 1, bottom_limit = N - 1;
    for (int row = 0, col = 0, cnt = N * N; cnt >= 1; cnt--) {
        if (row < bottom_limit && col == left_limit) {
            adj[row++][col] = cnt;
        } else if (col < right_limit && row == bottom_limit) {
            adj[row][col++] = cnt;
        } else if (row > top_limit && col == right_limit) {
            adj[row--][col] = cnt;
        } else if (col > left_limit && row == top_limit) {
            adj[row][col--] = cnt;
            if (col == left_limit + 1) {
                left_limit++, top_limit++, right_limit--, bottom_limit--;
            }
        } else if (row == top_limit && row == bottom_limit) {
            adj[row][col] = cnt;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    cin >> pos;
    make_snail(N);
    print_adj();
    cout << find_pos(pos).first << " " << find_pos(pos).second;
    return 0;
}