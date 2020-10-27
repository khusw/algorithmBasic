/*
    BOJ 1316 그룹 단어 체커
    https://www.acmicpc.net/problem/1316
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool alphabet[26];
int N;

bool solve(string str) {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        if (alphabet[str[i] - 'a'])
            return false;
        else {
            char tmp = str[i];
            alphabet[str[i] - 'a'] = true;

            while (1) {
                if (tmp != str[++i]) {
                    i--;
                    break;
                }
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (solve(input)) cnt++;
        memset(alphabet, false, sizeof(alphabet));
    }

    cout << cnt;

    return 0;
}