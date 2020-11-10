/*
    BOJ 1193 Find Fraction
    https://www.acmicpc.net/problem/1193
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int X;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> X;
    if (X == 1) {
        cout << 1 << "/" << 1 << endl;
        return 0;
    }

    int sum = 1;
    long long cnt = 0;
    int num = 1;

    while (1) {
        sum++;
        cnt += num;
        if (cnt >= X) break;
        num++;
    }

    int child = 1, parent = 1;

    if (sum % 2)
        child = sum - 1;
    else
        parent = sum - 1;

    while (1) {
        if (cnt == X) break;
        if (sum % 2) {
            parent++;
            child--;
        } else {
            child++;
            parent--;
        }
        cnt--;
    }

    cout << child << "/" << parent << endl;

    return 0;
}