/*
    BOJ 11057 오르막 수
    https://www.acmicpc.net/problem/11057
*/

#include <iostream>
#define MOD 10007

using namespace std;

int N, dp[1001][10];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++) result = (result + dp[N][i]) % MOD;

    cout << result % MOD << "\n";

    return 0;
}