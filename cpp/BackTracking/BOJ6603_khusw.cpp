/*
    BOJ 6603 로또
    https://www.acmicpc.net/problem/6603
*/

#include <iostream>
#define MAX 13

using namespace std;

int s[MAX];
int combi[MAX];
int k = -1;

void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << combi[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < k; i++) {
        combi[depth] = s[i];
        dfs(i + 1, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> k && k) {
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}