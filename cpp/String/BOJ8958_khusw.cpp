/*
    BOJ 8958 OX 퀴즈
    https://www.acmicpc.net/problem/8958
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    string str_arr[T];

    for (int i = 0; i < T; i++) {
        cin >> str_arr[i];
    }

    for (int i = 0; i < T; i++) {
        int cnt = 0;
        int sum = 0;
        int size = str_arr[i].length();
        for (int j = 0; j < size; j++) {
            if (str_arr[i][j] == 'O') {
                cnt++;
            } else if (str_arr[i][j] == 'X') {
                cnt = 0;
            }
            sum += cnt;
        }
        cout << sum << '\n';
    }

    return 0;
}