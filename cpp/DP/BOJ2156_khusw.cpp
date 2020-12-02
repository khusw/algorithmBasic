/*
    BOJ 2156 포도주 시식
    https://www.acmicpc.net/problem/2156
*/

#include <algorithm>
#include <iostream>

#define MAX 10001

using namespace std;

int n;
int wine[MAX], dp[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> wine[i];

    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }

    int answer = -1;
    for (int i = 0; i <= n; ++i) {
        answer = max(answer, dp[i]);
    }
    cout << answer;

    return 0;
}