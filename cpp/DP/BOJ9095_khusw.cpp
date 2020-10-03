/*
    BOJ 9095 1,2,3 더하기
    https://www.acmicpc.net/problem/9095
*/

#include <iostream>
#define MAX 11

using namespace std;

int D[MAX];
int T;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    int n;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 4; j <= n; j++) {
            D[j] = D[j - 1] + D[j - 2] + D[j - 3];
        }
        cout << D[n] << '\n';
    }

    return 0;
}