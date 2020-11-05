/*
    BOJ 2747 Fibonacci
    https://www.acmicpc.net/problem/2747
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int dp[46];
int n;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n]) return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    cout << fib(n) << endl;

    return 0;
}