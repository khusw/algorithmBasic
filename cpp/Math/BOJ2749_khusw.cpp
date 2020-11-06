/*
    BOJ 2749 Fibonacci 3
    https://www.acmicpc.net/problem/2749
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef long long ll;

ll n;
ll dp[1500050];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    dp[0] = 0, dp[1] = 1;
    for (int i = 0; i < 1500000; ++i) {
        dp[i + 2] = (dp[i + 1] + dp[i]) % 1000000;
    }
    cout << dp[n % 1500000];

    return 0;
}