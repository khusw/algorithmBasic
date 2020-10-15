/*
    BOJ 1699 제곱수의 합
    https://www.acmicpc.net/problem/1699
*/

#include <algorithm>
#include <iostream>
#define MAX 100001

using namespace std;

int N, dp[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];

    return 0;
}