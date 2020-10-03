/*
    BOJ 1436 영화감독 숌
    https://www.acmicpc.net/problem/1436
*/

#include <iostream>

using namespace std;

int N, i, tmp, flag, cnt;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    while (++i) {
        tmp = i, flag = 0;
        while (tmp) {
            if (tmp % 1000 == 666) flag = 1;
            tmp /= 10;
        }

        if (flag) {
            cnt++;
            if (cnt == N) break;
        }
    }

    cout << i;

    return 0;
}