/*
    BOJ 1912 연속합
    https://www.acmicpc.net/problem/1912

    DP 를 활용한 문제로,
    이전 누적 합(dp[i - 1])과 현재값(arr[i])의 총합한것과 현재 인덱스의 값 중 큰 값을 dp[] 배열에 넣는다.
    dp[i] = max(dp[i - 1], arr[i]);
    answer = max(answer, dp[i]);
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