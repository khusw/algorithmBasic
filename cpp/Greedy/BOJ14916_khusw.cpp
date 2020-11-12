/*
    BOJ 14916 거스름돈
    https://www.acmicpc.net/problem/14916
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, cnt;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    while (n != 0) {
        if (n % 5 == 0) {
            cnt += (n / 5);
            break;
        } else {
            cnt += 1;
            n -= 2;
        }
    }

    if (n >= 0)
        cout << cnt;
    else
        cout << "-1";

    return 0;
}