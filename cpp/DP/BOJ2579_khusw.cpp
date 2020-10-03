/*
    BOJ 2579 계단 오르기
    https://www.acmicpc.net/problem/2579
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    int adj[300];
    int D[300];

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> adj[i];
    }

    D[0] = adj[0];
    D[1] = max(adj[0] + adj[1], adj[1]);
    D[2] = max(adj[0] + adj[2], adj[1] + adj[2]);

    for (int i = 3; i < T; i++) {
        D[i] = max(D[i - 2] + adj[i], D[i - 3] + adj[i - 1] + adj[i]);
    }

    cout << D[T - 1];
    return 0;
}