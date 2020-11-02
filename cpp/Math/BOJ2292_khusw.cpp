/*
    BOJ 2292 벌집
    https://www.acmicpc.net/problem/2292
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef long long ll;

int n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    int cnt = 1;
    ll range = 1, temp = 1;

    while (1) {
        if (range >= n) break;
        temp = 6 * (cnt++);
        range += temp;
    }

    cout << cnt << endl;
    return 0;
}