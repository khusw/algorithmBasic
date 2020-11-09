/*
    BOJ 1717 집합의 표현
    https://www.acmicpc.net/submit/1717/23746201
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int parent[1000001];
int n, m, order, a, b;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) parent[i] = i;

    for (int i = 0; i < m; ++i) {
        cin >> order >> a >> b;
        if (!order) {
            unionParent(a, b);
        } else {
            if (findParent(a, b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}