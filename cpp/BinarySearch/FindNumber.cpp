/*
    BOJ 1920 수 찾기
    https://www.acmicpc.net/problem/1920
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N, M;
vector<ll> vec_n;

void binary_search(int start, int end, ll m) {
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (vec_n[mid] > m) {
            end = mid - 1;
        } else if (vec_n[mid] < m) {
            start = mid + 1;
        } else {
            cout << "1" << '\n';
            return;
        }
    }
    cout << "0" << '\n';
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll n;
        cin >> n;
        vec_n.push_back(n);
    }

    sort(vec_n.begin(), vec_n.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        ll m;
        cin >> m;
        binary_search(0, N - 1, m);
    }

    return 0;
}