/*
    BOJ 2193 이친수
    https://www.acmicpc.net/problem/2193
*/

#include <iostream>
#define MAX_N 91

using namespace std;

int N;
long long dp[MAX_N][2] = {{0, 0}, {0, 1}, {1, 0}};

// recursive
long long pinary(int n, int digit) {
    // base case
    if (n == 0) return (digit == 0 ? -1 : 1);
    if (dp[n][digit] != -1) return dp[n][digit];

    // operation
    if (digit == 0) {
        dp[n][digit] = pinary(n - 1, 0) + pinary(n - 1, 1);
        return dp[n][digit];
    } else if (digit == 1) {
        dp[n][digit] = pinary(n - 1, 0);
        return dp[n][digit];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = -1;

    long long result = pinary(N, 0) + pinary(N, 1);
    cout << result << "\n";

    /* iterative
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N][0] + dp[N][1] << "\n";
    */

    return 0;
}