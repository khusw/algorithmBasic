/*
    BOJ 2775 부녀회장이 될테야
    https://www.acmicpc.net/problem/2775
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int t, k, n;
int dp[15][15];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 1; i < 15; ++i) dp[0][i] = i;

    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            int sum = 0;
            for (int k = 1; k <= j; ++k) {
                sum += dp[i - 1][k];
            }
            dp[i][j] = sum;
        }
    }

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> k >> n;
        cout << dp[k][n] << endl;
    }

    return 0;
}