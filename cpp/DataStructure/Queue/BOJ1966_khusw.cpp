/*
    BOJ 1966 프린터 큐
    https://www.acmicpc.net/problem/1966
*/

#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int solve(queue<pair<int, int>>& q, priority_queue<int>& pq) {
    int cnt = 0;
    while (!q.empty()) {
        int idx = q.front().first;
        int val = q.front().second;
        q.pop();

        if (pq.top() == val) {
            cnt++;
            pq.pop();
            if (idx == M)
                return cnt;
        } else {
            q.push(make_pair(idx, val));
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        queue<pair<int, int>> q;  // (index, value)
        priority_queue<int> pq;   // value
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            q.push(make_pair(j, num));
            pq.push(num);
        }
        cout << solve(q, pq) << "\n";
    }

    return 0;
}