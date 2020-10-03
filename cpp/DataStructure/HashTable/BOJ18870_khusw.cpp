/*
    BOJ 18870 압축된 좌표
    https://www.acmicpc.net/problem/18870
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> vec;
vector<int> answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    vec.resize(N);
    answer.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int key = vec[i].second;
        int temp = cnt;

        answer[key] = temp;
        cnt++;

        while (i < N && vec[i].first == vec[i + 1].first) {
            ++i;
            key = vec[i].second;
            answer[key] = temp;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}