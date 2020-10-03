/*
    BOJ 2042 구간 합 구하기
    https://www.acmicpc.net/problem/2042
*/

#include <iostream>

typedef long long ll;
using namespace std;

int N, M, K;

ll build_tree(ll* arr, ll* tree, ll node, ll start, ll end) {
    if (start == end) return tree[node] = arr[start];

    ll mid = (start + end) / 2;
    return tree[node] = build_tree(arr, tree, node * 2, start, mid) + build_tree(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(ll* tree, ll node, ll start, ll end, ll index, ll data) {
    if (index > end || index < start) return;

    tree[node] += data;

    if (start == end) return;

    ll mid = (start + end) / 2;
    update(tree, node * 2, start, mid, index, data);
    update(tree, node * 2 + 1, mid + 1, end, index, data);
}

ll query(ll* tree, ll node, ll start, ll end, ll L, ll R) {
    if (L <= start && R >= end)
        return tree[node];
    else if (R < start || L > end)
        return 0;
    else {
        ll mid = (start + end) / 2;
        return query(tree, node * 2, start, mid, L, R) + query(tree, node * 2 + 1, mid + 1, end, L, R);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    ll* arr = new ll[N];
    ll* tree = new ll[4 * N];

    arr[0] = 0;
    tree[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build_tree(arr, tree, 1, 1, N);

    ll a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            ll data = c - arr[b];
            update(tree, 1, 1, N, b, data);
            arr[b] += data;
        } else if (a == 2) {
            cout << query(tree, 1, 1, N, b, c) << '\n';
        }
    }

    delete[] tree;
    delete[] arr;
    return 0;
}