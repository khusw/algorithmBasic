/*
    BOJ 11052 카드 구매하기
    https://www.acmicpc.net/problem/11052
*/

#include <algorithm>
#include <iostream>
#define MAX 1001

using namespace std;

int N, pack[MAX], dp[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> pack[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + pack[j]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}