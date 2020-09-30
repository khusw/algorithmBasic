/*
    BOJ 1929 소수 구하기
    https://www.acmicpc.net/problem/1929
*/

#include <iostream>

using namespace std;

int M, N;
int arr[1000001];

void find_prime() {
    for (int i = 2; i <= N; i++) {
        if (arr[i] == 0)
            continue;
        for (int j = i + i; j <= N; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (arr[i] != 0) cout << arr[i] << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;

    for (int i = 2; i <= N; i++) {
        arr[i] = i;
    }

    find_prime();

    return 0;
}