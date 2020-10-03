/*
    BOJ 2675 문자열 반복
    https://www.acmicpc.net/problem/2675
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R;
        string S;
        cin >> R >> S;

        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }

        printf("\n");
    }
    return 0;
}