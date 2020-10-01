/*
    BOJ 11399 ATM
    https://www.acmicpc.net/problem/11399
*/

#include <algorithm>
#include <iostream>
#define MAX 1001

using namespace std;

int N;
int P[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    int sum = 0;
    for (int i = 1; i < N; i++) {
        P[i] = P[i - 1] + P[i];
    }

    for (int i = 0; i < N; i++) {
        sum += P[i];
    }

    cout << sum;

    return 0;
}