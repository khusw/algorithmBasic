/*
    BOJ 15829 Hashing
    https://www.acmicpc.net/problem/15829
*/

#include <bits/stdc++.h>

using namespace std;

long long L, r = 31, M = 1234567891;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> L;
    char ch[L];

    for (int i = 0; i < L; ++i) cin >> ch[i];

    long long sum = 0, exponent = 1;
    for (int i = 0; i < L; ++i) {
        sum = (sum + (ch[i] - 'a' + 1) * exponent) % M;
        exponent = (exponent * r) % M;
    }

    cout << sum;

    return 0;
}