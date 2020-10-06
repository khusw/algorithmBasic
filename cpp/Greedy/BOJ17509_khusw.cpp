/*
    BOJ 17509 And the Winner is... Ourselves
    https://www.acmicpc.net/problem/17509
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> vec;

void solve() {
    int answer = 0, clock = 0;
    for (int i = 0; i < 11; i++) {
        clock += vec[i].first;
        answer += (clock + (vec[i].second * 20));
    }
    cout << answer;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 11; i++) {
        int d, v;
        cin >> d >> v;
        vec.push_back(make_pair(d, v));
    }

    sort(vec.begin(), vec.end());

    solve();

    return 0;
}