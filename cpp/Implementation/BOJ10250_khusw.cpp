/*
    BOJ 10250 ACM Hotel
    https://www.acmicpc.net/problem/10250
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int T, H, W, N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cin >> H >> W >> N;

        int cnt = 0, r = 0, c = 0;
        for (int i = 0; i < W; ++i) {
            c++;
            for (int j = H - 1; j >= 0; --j) {
                r++;
                cnt++;
                if (cnt == N) break;
            }
            if (cnt == N) break;
            r = 0;
        }

        if (c / 10 == 0)
            cout << r << "0" << c << endl;
        else
            cout << r << c << endl;
    }

    return 0;
}