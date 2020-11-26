/*
    PG 43165 Target Number
    https://programmers.co.kr/learn/courses/30/lessons/43165
*/

#include <bits/stdc++.h>

using namespace std;

int cnt;

void recursion(vector<int>& numbers, int target, int depth, int sum) {
    if (depth == numbers.size()) {
        if (sum == target)
            cnt++;
        return;
    }
    recursion(numbers, target, depth + 1, sum + numbers[depth]);
    recursion(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0, size = numbers.size();
    recursion(numbers, target, 0, 0);
    answer = cnt;
    return answer;
}