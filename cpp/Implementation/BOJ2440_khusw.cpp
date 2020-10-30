/*
    BOJ 2440 별 찍기 - 3
    https://www.acmicpc.net/problem/2440
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = n - i; j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}