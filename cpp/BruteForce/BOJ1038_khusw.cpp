/*
    BOJ 1038 감소하는 수
    https://www.acmicpc.net/problem/1038
*/

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> decrease;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int cnt = 0;
    int i, j, tmp;

    if (N <= 10) {
        cout << N << '\n';
    } else if (N == 1022) {
        cout << 9876543210 << '\n';
    } else if (N >= 1023) {
        cout << "-1" << '\n';
    } else {
        for (i = 1; i < 10; i++) {
            decrease.push(i);
            cnt++;
        }

        while (cnt < N) {
            i = decrease.front();
            decrease.pop();
            tmp = i % 10;

            for (j = 0; j < tmp; j++) {
                decrease.push(i * 10 + j);
                cnt++;
                if (cnt == N) {
                    cout << i * 10 + j << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}