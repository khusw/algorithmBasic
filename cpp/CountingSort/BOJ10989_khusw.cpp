/*
    BOJ 10989번 수 정렬하기 3
    https://www.acmicpc.net/problem/10989
*/

#include <iostream>

using namespace std;

int n;
int a[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < 10001; i++) {
        while (a[i] != 0) {
            cout << i << '\n';
            a[i]--;
        }
    }
}