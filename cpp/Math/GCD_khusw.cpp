/*
    GCD(Greatest Common Divisor)
    최대 공약수 알고리즘 (유클리드 알고리즘)

    두 자연수 a, b 가 주어졌을때,
    a > b 라 가정하고
    a % b = n 에서
    n 이 0 이면 b 가 최대 공약수 이며,
    n 이 0 이 아니면 n 이 0이 될때 까지 a 에 b 를 넣고, b 에 n 을 넣어서
    다시 나머지 연산을 수행한다.
*/

#include <iostream>

using namespace std;

int a, b;  // a > b 일때라고 가정
int answer;

// 반복문을 통한 최대 공약수 구하기
int gcd(int a, int b) {
    int result = a % b;
    while (result != 0) {
        a = b;
        b = result;
        result = a % b;
    }
    return b;
}

// 재귀 함수를 통한 최대 공약수 구하기
/*
int gcd(int a, int b) {
    int result = a % b;
    if (!result) {
        // n == 0 일때,
        return b;
    } else {
        // n != 일때,
        gcd(b, result);
    }
}
*/

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;

    answer = gcd(a, b);

    cout << answer;

    return 0;
}