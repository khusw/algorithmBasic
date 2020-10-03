/*
    BOJ 2475 검증수
    https://www.acmicpc.net/problem/2475
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