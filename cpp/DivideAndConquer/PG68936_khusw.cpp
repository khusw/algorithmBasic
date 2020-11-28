/*
    PG 68936 쿼드압축 후 세기
    https://programmers.co.kr/learn/courses/30/lessons/68936
*/

#include <vector>

using namespace std;

int cnt[2];

void divide_and_conquer(vector<vector<int>>& arr, int y, int x, int k) {
    bool flag = true;
    int base = arr[y][x];
    for (int i = y; i < y + k; ++i) {
        for (int j = x; j < x + k; ++j) {
            if (base != arr[i][j]) flag = false;
        }
    }

    if (flag)
        cnt[base]++;
    else {
        divide_and_conquer(arr, y, x, k / 2);
        divide_and_conquer(arr, y, x + k / 2, k / 2);
        divide_and_conquer(arr, y + k / 2, x, k / 2);
        divide_and_conquer(arr, y + k / 2, x + k / 2, k / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    divide_and_conquer(arr, 0, 0, arr.size());
    answer.resize(2);
    answer[0] = cnt[0];
    answer[1] = cnt[1];
    return answer;
}