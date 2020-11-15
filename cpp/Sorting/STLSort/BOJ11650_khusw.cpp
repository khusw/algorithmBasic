/*
    BOJ 11650 좌표 정렬
    https://www.acmicpc.net/problem/11650
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n;
vector<pair<int, int>> vec;

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < vec.size(); ++i) cout << vec[i].first << " " << vec[i].second << endl;

    return 0;
}