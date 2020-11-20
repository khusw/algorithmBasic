/*
    PG 42860 조이스틱
    https://programmers.co.kr/learn/courses/30/lessons/42860
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0, len = name.length(), cursor = 0;
    string init_str(len, 'A');

    while (1) {
        if (init_str[cursor] != name[cursor]) {
            int up_len = name[cursor] - 'A', down_len = 'Z' + 1 - name[cursor], min_num;
            min_num = min(up_len, down_len);
            answer += min_num;
            init_str[cursor] = name[cursor];
        }

        if (init_str == name) break;

        int left_len = 0, right_len = 0, left_idx = cursor, right_idx = cursor;
        // move left
        while (1) {
            left_idx--;
            left_len++;
            if (left_idx < 0) left_idx = len - 1;
            if (init_str[left_idx] != name[left_idx]) break;
        }

        // move right
        while (1) {
            right_idx++;
            right_len++;
            if (right_idx >= len) right_idx = 0;
            if (init_str[right_idx] != name[right_idx]) break;
        }

        if (left_len >= right_len) {
            cursor = right_idx;
            answer += right_len;
        } else if (left_len < right_len) {
            cursor = left_idx;
            answer += left_len;
        }
    }

    return answer;
}