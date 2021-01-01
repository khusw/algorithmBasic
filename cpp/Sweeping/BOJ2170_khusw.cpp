/*
    BOJ 2170 선 긋기
    https://www.acmicpc.net/problem/2170
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector<pair<int, int>> vec;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        vec.push_back({start, end});
    }

    sort(vec.begin(), vec.end(), comp);

    int start = vec[0].first, end = vec[0].second;
    for (int i = 1; i < vec.size(); ++i) {
        if (start <= vec[i].first && vec[i].first <= end && end < vec[i].second) {
            end = vec[i].second;
        } else if (vec[i].first > end) {
            answer += (end - start);
            start = vec[i].first;
            end = vec[i].second;
        }
    }

    answer += (end - start);
    cout << answer;

    return 0;
}