/*
    BOJ 2475 검증수
    https://www.acmicpc.net/problem/2475

    6자리 고유번호 중 앞 5자리는 00000 ~ 99999 으로 구성되고,
    나머지 6번째의 수는 검증수가 들어감
    검증수는 앞 5자리의 5개 숫자를 제곱한 수의 합을 10 으로 나눈 나머지임

    ex) 04256 -> 0 + 16 + 4 + 25 + 36 = 81 -> 81 % 10 => 1 
    6번째 수는 1 이됨.
*/

#include <cmath>
#include <iostream>

using namespace std;

int fixed_num[5];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    int answer = 0;

    for (int i = 0; i < 5; i++) {
        cin >> fixed_num[i];
        sum += pow(fixed_num[i], 2);
    }

    answer = sum % 10;

    printf("%d", answer);

    return 0;
}