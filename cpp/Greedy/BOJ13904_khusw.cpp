/*
    BOJ 13904 과제
    https://www.acmicpc.net/problem/13904
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, answer;
vector<pair<int, int>> vec;
int arr[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, w;
        cin >> d >> w;
        vec.push_back(make_pair(w, d));
    }

    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    for (int i = 0; i < n; ++i) {
        int end = vec[i].second;
        while (end >= 1) {
            if (!arr[end]) {
                arr[end] = vec[i].first;
                break;
            }
            end--;
        }
    }

    for (int i = 1; i <= 1000; ++i) answer += arr[i];

    cout << answer;

    return 0;
}