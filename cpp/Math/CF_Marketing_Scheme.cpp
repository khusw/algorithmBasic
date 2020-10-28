/*
    A. Marketing Scheme
    https://codeforces.com/contest/1437/problem/A
*/

#include <iostream>

using namespace std;

int T, l, r;

void solve() {
    int a = 2 * l;
    if (a > r) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        return;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> l >> r;
        solve();
    }

    return 0;
}