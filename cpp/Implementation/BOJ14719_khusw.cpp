/*
    BOJ 14719 빗물
    https://www.acmicpc.net/problem/14719
*/

#include <algorithm>
#include <iostream>

using namespace std;

int H, W, answer;
int arr[501];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> H >> W;
    for (int i = 0; i < W; i++) cin >> arr[i];

    for (int i = 1; i < W; i++) {
        int left = -1, right = -1, min_num = 0;

        for (int j = i; j >= 0; j--) left = max(left, arr[j]);

        for (int j = i; j < W; j++) right = max(right, arr[j]);

        min_num = min(left, right);
        answer += (min_num - arr[i]);
    }

    cout << answer;

    return 0;
}