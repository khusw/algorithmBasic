/*
    BOJ 1966 프린터 큐
    https://www.acmicpc.net/problem/1966
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int T, target;

void print_queue(priority_queue<pair<int, int>>& pq, int m) {
    int cnt = 0;
    while (!pq.empty()) {
        cnt++;
        if (pq.top().second == m) {
            cout << cnt << '\n';
            return;
        }
        pq.pop();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        priority_queue<pair<int, int>> pq;  // 중요도, 인덱스번호
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            pq.push(make_pair(temp, i));
            if (i == M) {
                target = temp;
            }
        }
        print_queue(pq, M);
    }

    return 0;
}