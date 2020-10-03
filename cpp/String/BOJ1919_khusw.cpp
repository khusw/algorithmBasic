/*
    BOJ 1919 애너그램 만들기
    https://www.acmicpc.net/problem/1919
*/

#include <iostream>
#include <string>

using namespace std;

int alphabet1[26], alphabet2[26];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++) {
        alphabet1[str1[i] - 'a']++;
    }

    for (int j = 0; j < str2.size(); j++) {
        alphabet2[str2[j] - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabet1[i] != alphabet2[i]) {
            cnt += abs(alphabet1[i] - alphabet2[i]);
        }
    }

    cout << cnt;

    return 0;
}