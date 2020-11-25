/*
    PG 42842 카펫
    https://programmers.co.kr/learn/courses/30/lessons/42842
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    vector<pair<int, int>> vec;
    for (int i = 1; i <= total; ++i)
        if (total % i == 0)
            vec.push_back(make_pair(i, total / i));

    for (int i = 0; i < vec.size(); ++i) {
        int x = vec[i].first, y = vec[i].second;  // 가로 , 세로
        if (x < y) continue;

        int cnt = 0;

        // E
        for (int j = 0; j < x; ++j) cnt++;

        // S
        for (int j = 1; j < y; ++j) cnt++;

        // W
        for (int j = x - 2; j >= 0; --j) cnt++;

        // N
        for (int j = y - 2; j > 0; --j) cnt++;

        if (cnt == brown) {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }

    return answer;
}