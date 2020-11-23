/*
    BOJ 1068 Tree
    https://www.acmicpc.net/problem/1068
*/

#include <iostream>
#include <vector>

using namespace std;

int n, d, root, answer;
vector<vector<int>> children;

void dfs(int node) {
    if (d == node) return;
    int size = children[node].size();

    switch (size) {
        case 0:  // leaf node
            answer++;
            return;
            break;
        case 1:  // has a one child
            if (children[node][0] == d) {
                answer++;
                break;
            }
        default:  // have children
            for (int i = 0; i < size; ++i)
                dfs(children[node][i]);
            break;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    children.resize(n);

    int p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        if (p == -1)
            root = i;
        else
            children[p].push_back(i);
    }
    cin >> d;

    dfs(root);
    cout << answer;

    return 0;
}