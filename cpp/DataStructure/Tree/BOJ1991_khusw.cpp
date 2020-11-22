/*
    BOJ 1991 Tree Traversal
    https://www.acmicpc.net/problem/1991
*/

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int n;
vector<char> parent, lc, rc;

void preorder(char root) {
    cout << root;
    if (lc[root - 'A'] != '.') preorder(lc[root - 'A']);
    if (rc[root - 'A'] != '.') preorder(rc[root - 'A']);
}

void inorder(char root) {
    if (lc[root - 'A'] != '.') inorder(lc[root - 'A']);
    cout << root;
    if (rc[root - 'A'] != '.') inorder(rc[root - 'A']);
}

void postorder(char root) {
    if (lc[root - 'A'] != '.') postorder(lc[root - 'A']);
    if (rc[root - 'A'] != '.') postorder(rc[root - 'A']);
    cout << root;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    parent.resize(n, '.');
    lc.resize(n, '.');
    rc.resize(n, '.');
    for (int i = 0; i < n; ++i) {
        char p, l, r;  // parent node, left child node, right child node
        cin >> p >> l >> r;
        if (p != '.' && l != '.') {
            parent[l - 'A'] = p;
            lc[p - 'A'] = l;
        }
        if (p != '.' && r != '.') {
            parent[r - 'A'] = p;
            rc[p - 'A'] = r;
        }
    }

    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');

    return 0;
}