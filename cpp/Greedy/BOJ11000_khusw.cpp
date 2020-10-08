/*
    BOJ 11000 강의실 배정
    https://www.acmicpc.net/problem/11000
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> vec;

void solve() {
    priority_queue<int, vector<int>, greater<int>> rooms;
    rooms.push(vec[0].second);

    for (int i = 1; i < N; i++) {
        if (rooms.top() <= vec[i].first) {
            rooms.pop();
            rooms.push(vec[i].second);
        } else {
            rooms.push(vec[i].second);
        }
    }
    cout << rooms.size();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        vec.push_back(make_pair(s, t));
    }

    sort(vec.begin(), vec.end());

    solve();

    return 0;
}