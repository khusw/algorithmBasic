/*
    BOJ 2630 색종이 만들기
    https://www.acmicpc.net/problem/2630
*/

#include <iostream>
#define MAX 128

using namespace std;

bool adj[MAX][MAX];
int answer[2] = {
    0,
};
int N;

void divide_and_conquer(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (adj[x][y] != adj[i][j]) {
                int s = size / 2;
                divide_and_conquer(x, y, s);
                divide_and_conquer(x + s, y, s);
                divide_and_conquer(x, y + s, s);
                divide_and_conquer(x + s, y + s, s);
                return;
            }
        }
    }
    answer[adj[x][y]]++;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    divide_and_conquer(0, 0, N);

    for (auto &ans : answer)
        cout << ans << '\n';

    return 0;
}