/*
    BOJ 1924 2007 년
    https://www.acmicpc.net/problem/1924
*/

#include <bits/stdc++.h>

using namespace std;

int x, y;
string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> x >> y;

    int cnt = 0;
    for (int i = 1; i <= x; ++i) {
        int day = month[i];
        for (int j = 1; j <= day; ++j) {
            cnt++;
            if (i == x && j == y) {
                cout << days[cnt % 7] << "\n";
                return 0;
            }
        }
    }

    return 0;
}