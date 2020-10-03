/*
    BOJ 1764 듣보잡
    https://www.acmicpc.net/problem/1764
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> unknown;
vector<string> answer;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    unknown.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> unknown[i];
    }

    sort(unknown.begin(), unknown.end());

    string str;
    for (int i = 0; i < M; i++) {
        cin >> str;

        if (binary_search(unknown.begin(), unknown.end(), str)) {
            answer.push_back(str);
        }
    }

    int answer_size = answer.size();

    sort(answer.begin(), answer.end());

    cout << answer_size << '\n';

    for (int i = 0; i < answer_size; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
