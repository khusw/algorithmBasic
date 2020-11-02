/*
    BOJ 2751 수 정렬하기 2
    https://www.acmicpc.net/problem/2751
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) cin >> vec[i];

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; ++i) cout << vec[i] << endl;
    return 0;
}