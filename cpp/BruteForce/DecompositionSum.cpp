/*
    BOJ 2231 분해합
    https://www.acmicpc.net/problem/2231

    어떤 자연수 N 이 주어지면, 그 자연수 N 에 대한 분해합은
    N + (N을 이루는 각 자리수의 합) 으로 구성된다.

    예를들면 자연수 245 에 대한 분해합은 245 + 2 + 4 + 5 => 256 이 되며
    256의 생성자는 245 이다.

    생성자의 갯수가 꼭 한개만 있는 것은 아니다.
    여러개가 존재하기도 한다라고 문제의 설명에 되어 있다.

    입력으로 자연수 N 이 주어졌을 때, N 이 생성할 수 있는 가장 작은 생성자를 구하는 프로그램을 작성해야 한다.
    생성자가 없다면 0을 출력한다.
    N 의 범위는 1 ~ 백만 이다.
*/

#include <iostream>
#define MAX 1000001

using namespace std;

int N;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    bool check = false;
    for (int i = 1; i < MAX; i++) {
        int tmp = i;
        int sum = 0;
        int answer = i;
        sum += i;
        while (tmp) {
            int re = tmp % 10;
            sum += re;
            tmp /= 10;
        }
        if (sum == N) {
            check = true;
            cout << answer;
            break;
        }
    }

    if (!check) {
        cout << 0;
    }

    return 0;
}