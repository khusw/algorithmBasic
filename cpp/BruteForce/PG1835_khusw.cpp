/*
    PG 1835 단체 사진 찍기
    https://programmers.co.kr/learn/courses/30/lessons/1835
*/

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool is_valid(char op, int num, int dist) {
    switch (op) {
        case '=':
            return dist == num;
            break;
        case '>':
            return dist > num;
            break;
        case '<':
            return dist < num;
            break;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string order = "ACFJMNRT";

    do {
        bool flag = true;
        for (string str : data) {
            char first = str[0], second = str[2], op = str[3];
            int num = str[4] - '0', diff = order.find(first) - order.find(second);
            int dist = abs(diff) - 1;

            if (is_valid(op, num, dist)) continue;
            flag = false;
            break;
        }
        if (flag) answer++;
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}