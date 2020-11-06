/*
    BOJ 1629 Multiply
    https://www.acmicpc.net/problem/1629
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef long long ll;

ll a, b, c;

ll exponentiation(ll base, ll exponent, ll moduler) {
    if (exponent == 0) return 1;

    ll n = exponentiation(base, exponent / 2, moduler);
    n = n * n % moduler;

    if (exponent % 2 == 0)
        return n;
    else
        return (base * n) % moduler;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;

    cout << exponentiation(a, b, c) << endl;

    return 0;
}