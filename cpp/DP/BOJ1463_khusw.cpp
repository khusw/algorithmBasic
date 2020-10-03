/*
    BOJ 1463 1로 만들기
    https://www.acmicpc.net/problem/1463
*/

#include <iostream>
#define MAX 1000001
#define MIN(A, B) A > B ? B : A

int D[MAX];
int N;

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    D[1] = 0;

    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + 1;
        if (i % 3 == 0)
            D[i] = MIN(D[i], D[i / 3] + 1);
        if (i % 2 == 0)
            D[i] = MIN(D[i], D[i / 2] + 1);
    }

    cout << D[N];

    return 0;
}