/*
    BOJ 2675 문자열 반복
    https://www.acmicpc.net/problem/2675

    문자열 S 가 입력으로 주어지고, 각 문자를 R 번 반복해서, 새 문자열 P 를 만든후
    출력하는 프로그램을 작성해야한다.
    첫번째 문자 R 번 반복, 두번째 문자 R 번 반복 ... n 번째 문자 R 번 반복 
    하는 식으로 해서 새로운 문자열 P 를 만든다

    입력으로 주어지는 문자들은
    QR Code alphanumeric 문자로 구성되며, 
    이는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 으로 구성되어있다.
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R;
        string S;
        cin >> R >> S;

        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }

        printf("\n");
    }
    return 0;
}