/*
    BOJ 10165 버스 노선
    https://www.acmicpc.net/problem/10165
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int start;
    int end;
    int idx;
} Pos;

vector<Pos> vec;

int n, m;

bool comp(Pos& p1, Pos& p2) {
    if (p1.start != p2.start) return p1.start < p2.start;
    return p1.end > p2.end;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int s, e;
        cin >> s >> e;
        if (s < e)
            vec.push_back({s, e, i});
        else {
            vec.push_back({s - n, e, i});
            vec.push_back({s, e + n, i});
        }
    }

    sort(vec.begin(), vec.end(), comp);

    vector<int> answer = {vec.front().idx};

    int temp = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[temp].end < vec[i].end) {
            answer.push_back(vec[i].idx);
            temp = i;
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}