/*
    BOJ 9465 스티커
    https://www.acmicpc.net/problem/9465
*/

#include <algorithm>
#include <iostream>
#define MAX 100001

using namespace std;

int T, N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        int value[2][MAX], dp[MAX][3] = {0};
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < N; k++) {
                cin >> value[j][k];
            }
        }

        for (int i = 0; i < N; i++) {
            dp[i + 1][0] = max(dp[i + 1][0], max(max(dp[i][0], dp[i][1]), dp[i][2]));
            dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][2]) + value[0][i]);
            dp[i + 1][2] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]) + value[1][i]);
        }

        int result = max(max(dp[N][0], dp[N][1]), dp[N][2]);
        cout << result << "\n";
    }

    return 0;
}