/*
    BOJ 1002 터렛
    https://www.acmicpc.net/problem/1002
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T, x1, y1, r1, x2, y2, r2;
    double s;

    cin >> T;

    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        s = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                cout << -1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (abs(r1 - r2) < s && s < r1 + r2) {
            cout << 2 << '\n';
        }
        else if (abs(r1 - r2) == s || s == r1 + r2) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}