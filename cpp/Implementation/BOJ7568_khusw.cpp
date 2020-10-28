/*
    BOJ 7568 덩치
    https://www.acmicpc.net/problem/7568
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, x, y;
vector<pair<int, int>> list;
vector<int> ranks;

void solve() {
    int size = list.size();
    for (int i = 0; i < size; ++i) {
        int cnt = 1;
        for (int j = 0; j < size; ++j) {
            if ((list[j].second > list[i].second) && (list[j].first > list[i].first)) cnt++;
        }
        ranks.emplace_back(cnt);
    }

    for (auto iter : ranks) {
        cout << iter << " ";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        list.emplace_back(make_pair(x, y));
    }

    solve();

    return 0;
}