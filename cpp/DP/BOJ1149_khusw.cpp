/*
    BOJ 1149 RGB 거리
    https://www.acmicpc.net/problem/1149 
*/

#include <algorithm>
#include <iostream>

using namespace std;

int N;
int adj[1001][3];
int D[1001][3];

void find_min_value() {
    for (int i = 1; i <= N; i++) {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + adj[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + adj[i][1];
        D[i][2] = min(D[i - 1][0], D[i - 1][1]) + adj[i][2];
    }

    int minimum;
    minimum = min(min(D[N][0], D[N][1]), D[N][2]);
    cout << minimum;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> adj[i][j];
        }
    }

    find_min_value();

    return 0;
}