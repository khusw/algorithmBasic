/*
    Basic Implementation - 1. Make Zigzag Array
*/

#include <bits/stdc++.h>

using namespace std;

int arr[5][5];

enum {
    UP,
    DOWN
} dir;

int main() {
    int i, j;
    int cnt = 1;
    int x = -1, y = 0;

    dir = UP;
    int total = 5 * 5;

    while (cnt <= total) {
        if (x == 5 - 1 && cnt <= total) {
            arr[++y][x] = cnt++;
            dir = DOWN;
        }

        if (y == 5 - 1 && cnt <= total) {
            arr[y][++x] = cnt++;
            dir = UP;
        }

        if (y == 0 && cnt <= total) {
            arr[y][++x] = cnt++;
            dir = DOWN;
        }

        if (x == 0 && cnt <= total) {
            arr[++y][x] = cnt++;
            dir = UP;
        }

        if (dir == UP && x != 5 - 1 && y != 0 && cnt <= total) {
            cnt += 2;
            arr[--y][++x] = cnt;
        }

        if (dir == DOWN && y != 5 - 1 && x != 0 && cnt <= total) {
            cnt += 2;
            arr[++y][--x] = cnt;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}