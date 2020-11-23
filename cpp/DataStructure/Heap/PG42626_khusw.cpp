/*
    PG 42626 더 맵게
    https://programmers.co.kr/learn/courses/30/lessons/42626
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); ++i) pq.push(scoville[i]);

    while (!pq.empty()) {
        if (pq.top() >= K) break;
        if (pq.size() < 2) break;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }

    while (!pq.empty()) {
        if (pq.top() < K) answer = -1;
        break;
    }

    return answer;
}