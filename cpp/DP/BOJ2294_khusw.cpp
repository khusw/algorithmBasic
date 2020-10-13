/*
    BOJ 2294 동전 2
    https://www.acmicpc.net/problem/2294
*/

#include <algorithm>
#include <iostream>
#define MAX_N 101
#define MAX_K 10001
#define IMPOSSIBLE 987654321

using namespace std;

int N, K, cost[MAX_N], dp[MAX_N][MAX_K];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> cost[i];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = IMPOSSIBLE;

    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
        for (int j = 0; j <= K; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            int tmp = j + cost[i];
            if (tmp <= K) dp[i][tmp] = min(dp[i][tmp], dp[i][j] + 1);
        }
    }

    if (dp[N - 1][K] == IMPOSSIBLE)
        cout << "-1\n";
    else
        cout << dp[N - 1][K] << "\n";

    return 0;
}