/*
    BOJ 9252 LCS 2
    https://www.acmicpc.net/problem/9252
*/

#include <algorithm>
#include <iostream>
#include <string>

#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string base_str, compare_str;
    cin >> base_str;
    cin >> compare_str;

    int max_len = 0;
    for (int i = 1; i <= compare_str.length(); ++i) {
        for (int j = 1; j <= base_str.length(); ++j) {  // 문자열의 최대길이 1000 이므로 O(N^2) 에 가능
            if (compare_str[i - 1] == base_str[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (max_len < dp[i][j]) max_len = dp[i][j];
        }
    }

    string answer;
    for (int i = compare_str.length(); i > 0; --i) {
        for (int j = base_str.length(); j > 0; --j) {
            if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1] && dp[i][j] > dp[i - 1][j - 1] && dp[i][j] == max_len) {
                answer = base_str[j - 1] + answer;
                max_len--;
                break;
            }
        }
    }

    cout << answer.length() << "\n";
    cout << answer;

    return 0;
}