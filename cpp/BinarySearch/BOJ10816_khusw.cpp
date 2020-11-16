/*
    BOJ 10816 숫자 카드 2
    https://www.acmicpc.net/problem/10816
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> vec;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        cout << upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num) << " ";
    }

    return 0;
}