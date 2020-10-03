/*
    BOJ 1484 다이어트
    https://www.acmicpc.net/problem/1484
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
int W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W;

    bool check = false;

    int left = 1;
    int right = 1;

    while (left <= right and right <= MAX) {
        int G = right * right - left * left;

        if (G < W)
            right++;
        else if (G == W) {
            check = true;
            cout << right << '\n';
            right++;
        } else {
            left++;
        }
    }

    if (!check) {
        cout << -1 << '\n';
    }
    return 0;
}