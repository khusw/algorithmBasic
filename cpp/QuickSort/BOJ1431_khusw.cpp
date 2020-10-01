/*
    BOJ 1431 조금 더 복잡한 문자열 정렬
    https://www.acmicpc.net/problem/1431

    시리얼 번호를 정렬하는 문자열 문제
    모든 시리얼 번호는 대문자 숫자로 구성
    두개의 입력 A, B 가 올때,
    A 가 B 보다 먼저 앞에 오는 경우는
    1. A, B 의 길이가 서로 다르면, 짧은게 먼저 앞으로 온다.
    2. 서로 길이가 같으면, A 의 모든 자리수 합과 B 의 모든 자리수 합을 비교해서 작은합을 가지는게 먼저 온다
    (자리수의 합이란 것은 숫자인 놈만 더하겠다 라는 의미다.)
    3. 두 조건으로도 비교 불가능하면 사전순으로 정렬 (숫자가 알파벳 보다 사전순으로 적다.)
*/

#include <algorithm>
#include <iostream>

using namespace std;

int n;
string a[20000];

int getSum(string a) {
    int length = a.length(), sum = 0;  // sum 은 문쟈열 a 에 속하는 모든 숫자들의 합을 구하기 위한 변수
    for (int i = 0; i < length; i++) {
        // 숫자인 경우에만 더하기 위한 조건문
        // 두 문자를 뺀다는 것은 아스키 코드 값을 뺀다는 말과 같음
        // 0 과 9 사이의 아스키 코드값에 속하는지를 묻는 조건문임.
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
            // 이 조건에 속하면 숫자에 해당하는 아스키 코드 값을 갖고 있다는 의미이며,
            // 현재 문자 - 0 을하면 해당하는 숫자가 나옴
            // 문자열로써 0 은 아스키 코드 값으로 48 이고, 입력된 문자(a[i]) 의 아스키 코드 값을 서로 빼면
            // 그 차액이 바로 입력한 문자의 숫자 값이 됨.
            // 예를 들어 a[i] = 4 라면 아스키 코드 값으로 52 가 되고, 0 은 아스키 코드값 48 이므로
            // 둘의 차액인 4 가 입력된 숫자를 의미하며, sum 에 그만큼 더하면 곧 4를 더하는게 됨.
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare(string a, string b) {
    if (a.length() < b.length()) {
        // 앞에가 더 적은 글자수를 가질 때
        return 1;
    } else if (a.length() > b.length()) {
        // 뒤에가 더 적은 글자수를 가질 때
        return 0;
    } else {
        // 두 개의 글자수가 같을때
        // getSum 이라는 custom 함수를 제작하여
        // 문자열 내에서 숫자만 추출해서 그 합을 리턴하게 하고
        // 숫자의 합을 통해서 두 문자를 비교
        int aSum = getSum(a);
        int bSum = getSum(b);
        if (aSum != bSum) {
            // 두 문자의 숫자의 합이 동일하지 않으면
            // 둘 중 숫자의 합이 작은게 먼저오도록 리턴 값을 조정하고,
            return aSum < bSum;
        } else {
            // 두 문자열의 숫자의 합이 같은 경우 (숫자로 비교할 수 있는게 아니므로)
            // 문자열의 사전순 자체를 비교해서 리턴.
            return a < b;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}
