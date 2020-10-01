/*
    BOJ 8958 OX 퀴즈
    https://www.acmicpc.net/problem/8958

    O 와 X 로 주어진 문자열이 주어지고,
    O 의 갯수에 따라 점수가 결정된다.

    OOXXOXXOOO 이면 점수 카운팅을
    1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10 이 된다.

    O 의 갯수가 점차 누적 되었다가 X 를 만나게 되면 0 으로 초기화 되는 것.
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