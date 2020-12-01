/*
    BOJ 1932 정수 삼각형
    https://www.acmicpc.net/problem/1932
*/

#include <bits/stdc++.h>

#define MAX 501

using namespace std;

int n;
int dp[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i][j] + dp[i - 1][j], dp[i][j] + dp[i - 1][j - 1]);
        }
    }

    int answer = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

    return 0;
}