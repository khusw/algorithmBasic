/*
    PG 12911 다음 큰 숫자
    https://programmers.co.kr/learn/courses/30/lessons/12911
*/

#include <string>

using namespace std;

bool number_of_one(int num1, int num2) {
    int cnt1 = 0, cnt2 = 0;
    while (num1 != 0) {
        int temp = num1 % 2;
        if (temp == 1) cnt1++;
        num1 /= 2;
    }

    while (num2 != 0) {
        int temp = num2 % 2;
        if (temp == 1) cnt2++;
        num2 /= 2;
    }

    if (cnt1 == cnt2)
        return true;
    else
        return false;
}

int solution(int n) {
    int answer = n + 1;

    while (1) {
        if (number_of_one(n, answer))
            break;
        else
            answer++;
    }

    return answer;
}