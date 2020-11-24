/*
    PG 42747 H-Index
    https://programmers.co.kr/learn/courses/30/lessons/42747#
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int i;
    for (i = 1; i <= citations.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < citations.size(); ++j) {
            if (citations[j] >= i) cnt++;
        }
        if (cnt < i) {
            answer = i - 1;
            break;
        }
    }

    if (i > citations.size()) answer = citations.size();

    return answer;
}