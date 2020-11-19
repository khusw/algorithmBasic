/*
    PG 42587 프린터
    https://programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, size = priorities.size();

    priority_queue<int> pq;   // value
    queue<pair<int, int>> q;  // index, value
    for (int i = 0; i < size; ++i) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int idx = q.front().first;
        int val = q.front().second;
        q.pop();

        if (pq.top() == val) {
            answer++;
            pq.pop();
            if (idx == location) {
                return answer;
            }
        } else {
            q.push(make_pair(idx, val));
        }
    }
    return answer;
}