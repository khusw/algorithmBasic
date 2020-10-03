/*
    BOJ 1912 연속합
    https://www.acmicpc.net/problem/1912
*/

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    int arr[n];
    int dp[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int answer = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}