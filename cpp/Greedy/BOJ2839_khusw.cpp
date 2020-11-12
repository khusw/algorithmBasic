/*
    BOJ 2839 설탕 배달
    https://www.acmicpc.net/problem/2839
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
            n -= 3;
        }
    }

    if (n < 0)
        cout << "-1";
    else
        cout << cnt;

    return 0;
}