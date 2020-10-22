/*
    BOJ 2098 외판원 순회
    https://www.acmicpc.net/problem/2098
*/
#include <cstring>
#include <iostream>
#define IMPOSSIBLE 987654321

using namespace std;

int N;
int W[16][16], dp[16][1 << 16];

int TSP(int current, int visited) {
    int &ret = dp[current][visited];
    if (ret != -1) return ret;

    if (visited == (1 << N) - 1) {
        if (W[current][0] != 0) return W[current][0];
        return IMPOSSIBLE;
    }

    ret = IMPOSSIBLE;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i) || W[current][i] == 0) continue;
        ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    cout << TSP(0, 1) << "\n";

    return 0;
}