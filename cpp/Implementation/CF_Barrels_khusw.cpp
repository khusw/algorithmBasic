/*
    B. Barrels
    https://codeforces.com/contest/1430/problem/B
*/

#include <algorithm>
#include <iostream>
#define MAX 200001

using namespace std;

int T;
int arr[MAX];

void solve(int n, int k) {
    bool all_empty = true;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) all_empty = false;
    }

    if (all_empty) {
        cout << "0\n";
        return;
    }

    sort(arr, arr + n);
    long long result = arr[n - 1];
    for (int i = 0; i < k; i++) {
        result += arr[n - 2 - i];
    }
    cout << result << "\n";
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        solve(n, k);
    }

    return 0;
}