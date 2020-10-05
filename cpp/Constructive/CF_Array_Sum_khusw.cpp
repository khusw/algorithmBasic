/*
    B. Array Sum
    https://codeforces.com/contest/1408/problem/B
*/

#include <iostream>

using namespace std;

int T;

void find_answer(int a[], int n, int k) {
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            cnt++;
        }
    }

    if (cnt == 0)
        cout << 1 << '\n';
    else {
        if (k == 0)
            cout << -1 << '\n';
        else
            cout << (cnt + k - 1) / k << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;

        k--;
        int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        find_answer(a, n, k);
    }

    return 0;
}