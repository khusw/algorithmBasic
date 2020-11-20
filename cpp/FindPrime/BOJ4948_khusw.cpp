/*
    BOJ 4948 Bertrand's postulate
    https://www.acmicpc.net/problem/4948
*/

#include <bits/stdc++.h>

#define MAX 250000
#define endl "\n"

using namespace std;

int n;
int arr[MAX];

void make_eratosthenes_sieve() {
    for (int i = 2; i < MAX; ++i) arr[i] = i;

    for (int i = 2; i < MAX; ++i) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j < MAX; j += i) arr[j] = 0;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    make_eratosthenes_sieve();

    while (1) {
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (arr[i] != 0) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}