/*
    BOJ 11053 가장 긴 증가하는 부분 수열
    https://www.acmicpc.net/problem/11053
*/

#include <iostream>

#define MAX 1001

using namespace std;

int N, answer;
int arr[MAX], dp[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        for (int j = 0; j <= i; ++j) {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (int i = 0; i < N; ++i)
        if (answer < dp[i])
            answer = dp[i];

    cout << answer;

    return 0;
}