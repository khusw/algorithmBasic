/*
    PG 42885 구명보트
    https://programmers.co.kr/learn/courses/30/lessons/42885#
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, size = people.size();

    sort(people.begin(), people.end());

    int s = 0, e = size - 1;
    while (s <= e) {
        if (people[s] + people[e] <= limit) {
            ++s;
            --e;
        } else {
            --e;
        }
        ++answer;
    }

    return answer;
}