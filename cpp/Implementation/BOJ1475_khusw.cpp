/*
    BOJ 1475 방 번호
    https://www.acmicpc.net/problem/1475
*/

#include <algorithm>
#include <iostream>

using namespace std;

int N;
int digit[10];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    while (N != 0) {
        digit[N % 10]++;
        N /= 10;
    }

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (i != 9 && i != 6) {
            cnt = max(cnt, digit[i]);
        }
    }

    cout << max(cnt, (digit[6] + digit[9] + 1) / 2);

    return 0;
}