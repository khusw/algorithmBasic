/*
    BOJ 1157 단어 공부
    https://www.acmicpc.net/problem/1157
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;

    cin >> str;

    int str_len = str.size();
    int alphabet_cnt[100] = {
        0,
    };

    for (char ch : str) {
        if ('a' <= ch) ch -= 32;
        alphabet_cnt[ch]++;
    }

    char answer;
    int max_cnt = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (max_cnt < alphabet_cnt[i]) {
            max_cnt = alphabet_cnt[i];
            answer = i;
        } else if (max_cnt == alphabet_cnt[i]) {
            answer = '?';
        }
    }

    printf("%c", answer);

    return 0;
}