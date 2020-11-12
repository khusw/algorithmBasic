/*
    BOJ 5585 거스름돈
    https://www.acmicpc.net/problem/5585
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, cnt;
int coins[6] = {500, 100, 50, 10, 5, 1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    n = 1000 - n;

    for (int i = 0; i < 6; ++i) {
        while (n - coins[i] >= 0) {
            n -= coins[i];
            cnt++;
            if (n == 0) {
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}