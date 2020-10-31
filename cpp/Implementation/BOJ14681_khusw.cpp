/*
	BOJ 14681 사분면 고르기 
	https://www.acmicpc.net/problem/14681 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0)
        cout << 1 << endl;
    else if (x > 0 && y < 0)
        cout << 4 << endl;
    else if (x < 0 && y > 0)
        cout << 2 << endl;
    else
        cout << 3 << endl;

    return 0;
}