/*
    BOJ 11047 Coin 0
    https://www.acmicpc.net/problem/11047
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K, cnt;
    cin >> N >> K;

    vector<int> coin_vec(N);

    for (int i = 0; i < N; i++) {
        cin >> coin_vec[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) {
            break;
        }

        if (coin_vec[i] > K) {
            continue;
        }

        cnt += K / coin_vec[i];
        K %= coin_vec[i];
    }

    return 0;
}
