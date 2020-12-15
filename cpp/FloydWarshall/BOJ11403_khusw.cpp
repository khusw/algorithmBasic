/*
    BOJ 11403 경로 찾기
    https://www.acmicpc.net/problem/11403
*/

#include <algorithm>
#include <iostream>

#define MAX 100
#define INF 1e9

using namespace std;

int n;
int dist[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (!dist[i][j]) dist[i][j] = INF;
        }
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
                cout << 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}