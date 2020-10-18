/*
    BOJ 10844 쉬운 계단 수
    https://www.acmicpc.net/problem/10844
*/

#include <iostream>
#define MOD 1000000000

using namespace std;

int N, dp[101][10];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][0] = dp[i - 1][1] % MOD;
            else if (j == 9)
                dp[i][9] = dp[i - 1][8] % MOD;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int result = 0;
    for (int i = 1; i < 10; i++) result = (result + dp[N][i]) % MOD;

    cout << result % MOD;

    return 0;
}