/*
    BOJ 11279 최대 힙
    https://www.acmicpc.net/problem/11279
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (!(x) && pq.empty()) {
            cout << 0 << '\n';
        } else if (!(x)) {
            cout << pq.top() << '\n';
            pq.pop();
        } else {
            pq.push(x);
        }
    }

    return 0;
}