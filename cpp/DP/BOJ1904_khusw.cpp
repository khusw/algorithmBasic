/*
    BOJ 1904 01타일
    https://www.acmicpc.net/problem/1904
*/

#include <iostream>
#define MAX 1000001

using namespace std;

int N, dp[MAX];

int tile(int n) {
    // base case
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (dp[n] != -1) return dp[n];

    // operation
    dp[n] = (tile(n - 1) + tile(n - 2)) % 15746;
    return dp[n];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i <= N; i++)
        dp[i] = -1;

    cout << tile(N);

    return 0;
}