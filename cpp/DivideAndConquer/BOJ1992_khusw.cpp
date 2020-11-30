/*
    BOJ 1992 Quad Tree
    https://www.acmicpc.net/problem/1992
*/

#include <bits/stdc++.h>

#define MAX 65

using namespace std;

int n;
int adj[MAX][MAX];

void divide_and_conquer(int y, int x, int size) {
    if (size == 1) {
        cout << adj[y][x];
        return;
    }

    bool one = true, zero = true;
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (adj[i][j] == 0) one = false;
            if (adj[i][j] == 1) zero = false;
        }
    }

    if (one) {
        cout << 1;
        return;
    }

    if (zero) {
        cout << 0;
        return;
    }

    cout << "(";
    divide_and_conquer(y, x, size / 2);
    divide_and_conquer(y, x + size / 2, size / 2);
    divide_and_conquer(y + size / 2, x, size / 2);
    divide_and_conquer(y + size / 2, x + size / 2, size / 2);
    cout << ")";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
            adj[i][j] = str[j] - '0';
    }

    divide_and_conquer(0, 0, n);

    return 0;
}