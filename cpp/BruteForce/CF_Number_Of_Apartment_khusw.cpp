/*
    A. Number Of Apartment
    https://codeforces.com/contest/1430/problem/0
*/

#include <iostream>
#include <vector>

using namespace std;

int T;

void solve(int n) {
    bool is_empty = true;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            for (int k = 0; k < n + 1; k++) {
                if (n == (3 * i) + (5 * j) + (7 * k)) {
                    cout << i << " " << j << " " << k << "\n";
                    is_empty = false;
                    return;
                }
            }
        }
    }
    if (is_empty) cout << "-1\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}