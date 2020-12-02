/*
    PG 42895 N 으로 표현
    https://programmers.co.kr/learn/courses/30/lessons/42895#
*/

#include <algorithm>
#include <unordered_set>

#define MAX 8

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    unordered_set<int> s[MAX];
    int base = 0;

    for (int i = 0; i < MAX; ++i) {
        base = 10 * base + 1;
        s[i].insert(base * N);
    }

    if (number / 10 == 0) {
        if (s[0].count(number) > 0) {
            answer = 1;
            return answer;
        }
    }

    for (int i = 1; i < MAX; ++i) {
        for (int j = 0; j < i; ++j) {
            for (auto op1 : s[j]) {
                for (auto op2 : s[i - j - 1]) {
                    s[i].insert(op1 + op2);
                    s[i].insert(op1 - op2);
                    s[i].insert(op1 * op2);
                    if (op2 != 0) s[i].insert(op1 / op2);
                }
            }
        }
        if (s[i].count(number) > 0) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}