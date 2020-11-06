/*
    BOJ 9471 피사노 주기
    https://www.acmicpc.net/problem/9471
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef long long ll;

int p, n, m;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> n >> m;

        int m1 = 0, m2 = 1, cnt = 0;
        while (1) {
            if (m1 == 0 && m2 == 1 && cnt != 0) break;
            int temp = m1;
            m1 = m2;
            m2 = (temp + m1) % m;
            cnt++;
        }
        cout << n << " " << cnt << endl;
    }

    return 0;
}