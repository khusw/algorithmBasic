/*
    BOJ 5622 다이얼
    https://www.acmicpc.net/problem/5622
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

    string input;
    cin >> input;

    int sum = 0;
    for (int i = 0; i < input.length(); ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < s[j].length(); ++k) {
                if (input[i] == s[j][k]) {
                    sum += (j + 3);
                }
            }
        }
    }
    cout << sum;

    return 0;
}