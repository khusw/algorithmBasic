/*
    BOJ 2231 분해합
    https://www.acmicpc.net/problem/2231
*/

#include <iostream>
#define MAX 1000001

using namespace std;

int N;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    bool check = false;
    for (int i = 1; i < MAX; i++) {
        int tmp = i;
        int sum = 0;
        int answer = i;
        sum += i;
        while (tmp) {
            int re = tmp % 10;
            sum += re;
            tmp /= 10;
        }
        if (sum == N) {
            check = true;
            cout << answer;
            break;
        }
    }

    if (!check) {
        cout << 0;
    }

    return 0;
}