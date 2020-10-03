/*
    BOJ 2798
    https://www.acmicpc.net/problem/2798
*/

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    int cardNum[100];
    int result = 0;
    for (int i = 0; i < N; i++) {
        cin >> cardNum[i];
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (cardNum[i] + cardNum[j] + cardNum[k] <= M && M - (cardNum[i] + cardNum[j] + cardNum[k]) < M - result) {
                    result = cardNum[i] + cardNum[j] + cardNum[k];
                }
            }
        }
    }

    cout << result;
    return 0;
}