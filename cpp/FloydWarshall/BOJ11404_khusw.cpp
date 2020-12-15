/*
    BOJ 11404 Floyd Warshall
    https://www.acmicpc.net/problem/11404
*/

#include <algorithm>
#include <iostream>

#define INF 1e9
#define MAX 100

using namespace std;

int n, m;
int dist[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = i == j ? 0 : INF;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}