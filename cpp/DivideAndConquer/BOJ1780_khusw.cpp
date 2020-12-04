/*
    BOJ 1780 종이의 갯수
    https://www.acmicpc.net/problem/1780
*/

#include <bits/stdc++.h>

#define MAX 2188

using namespace std;

int n;
int adj[MAX][MAX];
int arr[3];  // -1, 0, 1

void divide_and_conquer(int y, int x, int size) {
    if (size == 1) {
        int num = adj[y][x];
        if (num == -1)
            arr[0]++;
        else if (num == 0)
            arr[1]++;
        else if (num == 1)
            arr[2]++;
        return;
    }

    bool minus = true, zero = true, one = true;
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (adj[i][j] != -1) minus = false;
            if (adj[i][j] != 0) zero = false;
            if (adj[i][j] != 1) one = false;
        }
    }

    if (minus) {
        arr[0]++;
        return;
    }

    if (zero) {
        arr[1]++;
        return;
    }

    if (one) {
        arr[2]++;
        return;
    }

    divide_and_conquer(y, x, size / 3);
    divide_and_conquer(y, x + size / 3, size / 3);
    divide_and_conquer(y, x + (size / 3) * 2, size / 3);

    divide_and_conquer(y + size / 3, x, size / 3);
    divide_and_conquer(y + size / 3, x + size / 3, size / 3);
    divide_and_conquer(y + size / 3, x + (size / 3) * 2, size / 3);

    divide_and_conquer(y + (size / 3) * 2, x, size / 3);
    divide_and_conquer(y + (size / 3) * 2, x + size / 3, size / 3);
    divide_and_conquer(y + (size / 3) * 2, x + (size / 3) * 2, size / 3);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    divide_and_conquer(0, 0, n);
    for (int i = 0; i < 3; ++i) cout << arr[i] << "\n";

    return 0;
}