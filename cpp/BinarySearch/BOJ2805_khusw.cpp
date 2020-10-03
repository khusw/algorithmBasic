/*
    BOJ 2805 나무 자르기
    https://www.acmicpc.net/problem/2805
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
ll M;
vector<ll> tree_list;

void binary_search(ll start, ll end) {
    while (start + 1 < end) {
        ll mid = (start + end) / 2;
        ll temp = 0;
        for (int i = 0; i < N; i++) {
            if (tree_list[i] - mid > 0) {
                temp = temp + (tree_list[i] - mid);
            }
        }

        if (temp >= M) {
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

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll tree;
        cin >> tree;
        tree_list.push_back(tree);
    }

    binary_search(0, 1000000000);
    return 0;
}