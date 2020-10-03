/*
    BOJ 1654 랜선 자르기
    https://www.acmicpc.net/problem/1654
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int K, N;
vector<ll> line_list;

void binary_search(ll start, ll end) {
    while (start + 1 < end) {
        ll mid = (start + end) / 2;
        ll temp = 0;
        for (int i = 0; i < K; i++) {
            temp = temp + (line_list[i] / mid);
        }
        if (temp >= N) {
            start = mid;
        } else {
            end = mid;
        }
    }
    cout << start << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        ll line;
        cin >> line;
        line_list.push_back(line);
    }

    binary_search(0, 2147483648);

    return 0;
}