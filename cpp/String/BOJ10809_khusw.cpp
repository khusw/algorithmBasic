/*
    BOJ 10809 알파벳 찾기
    https://www.acmicpc.net/problem/10809
*/

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;

    cin >> str;

    int str_len = str.size();
    char ch;

    int alphabet[123];

    fill(alphabet, alphabet + 123, -1);

    for (int i = 0; i < str_len; i++) {
        ch = str[i];
        if (alphabet[ch] <= 0) {
            alphabet[ch] = i;
        }
    }

    for (int i = 97; i <= 122; i++) {
        cout << alphabet[i] << ' ';
    }

    return 0;
}
