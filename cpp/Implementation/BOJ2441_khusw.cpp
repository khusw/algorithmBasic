/*
    BOJ 2441 별 찍기 - 4
    https://www.acmicpc.net/problem/2441
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }

        for (int j = N - i; j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }
}