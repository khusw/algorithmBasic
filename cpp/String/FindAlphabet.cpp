/*
    BOJ 10809 알파벳 찾기
    https://www.acmicpc.net/problem/10809

    알파벳 소문자로 이뤄진 문자 S 가 주어지고, 
    각 알파벳에 대해서 단어내에 있다면 처음 등장하는 위치를 출력하고
    아예 포함되어 있지 않으면 -1 을 출력한다. 
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

/*
    배열 초기화는 보통 
    arr = {0,} 으로 전체 초기화가 되는데
    이상하게 음수의 경우 초기화가 되지 않았다.

    그래서 algorithm 헤더의 fill 함수를 이용하여 초기화를 직접해줬다.
*/