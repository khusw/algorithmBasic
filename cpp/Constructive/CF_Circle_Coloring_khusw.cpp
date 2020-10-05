/*
    A. Circle Coloring
    https://codeforces.com/contest/1408/problem/A
*/

#include <iostream>

using namespace std;

int T;

void find_p(int n, int a[], int b[], int c[]) {
    int p[n];
    p[0] = a[0];

    int i = 1;
    for (; i < n - 1; i++) {
        if (p[i - 1] != a[i])
            p[i] = a[i];
        else if (p[i - 1] != b[i])
            p[i] = b[i];
        else if (p[i - 1] != c[i])
            p[i] = c[i];
    }

    if (p[0] != a[i] && p[i - 1] != a[i])
        p[i] = a[i];
    else if (p[0] != b[i] && p[i - 1] != b[i])
        p[i] = b[i];
    else if (p[0] != c[i] && p[i - 1] != c[i])
        p[i] = c[i];

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        int a[N], b[N], c[N];

        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }

        for (int j = 0; j < N; j++) {
            cin >> b[j];
        }

        for (int j = 0; j < N; j++) {
            cin >> c[j];
        }

        find_p(N, a, b, c);
    }

    return 0;
}