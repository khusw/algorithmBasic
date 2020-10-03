/*
    BOJ 1759 암호 만들기
    https://www.acmicpc.net/problem/1759
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define MOEUM 5
#define MAX 16

using namespace std;

char arr[MAX];
set<char> moeum({'a', 'e', 'i', 'o', 'u'});
vector<char> dfs_vec;
int L, C;

void dfs(int depth, int moeum_num, int jaeum_num, int start) {
    if (depth == L - 1) {
        if (moeum_num < 1 || jaeum_num < 2) {
            return;
        }

        for (int i = 0; i < L; i++) {
            cout << dfs_vec[i];
        }
        cout << '\n';
        return;
    }

    if (start >= C) {
        return;
    }

    if (L - (moeum_num + jaeum_num) > C - start) {
        return;
    }

    for (int i = start; i < C; i++) {
        dfs_vec.push_back(arr[i]);

        if (moeum.find(arr[i]) == moeum.end()) {
            dfs(depth + 1, moeum_num, jaeum_num + 1, i + 1);
        } else {
            dfs(depth + 1, moeum_num + 1, jaeum_num, i + 1);
        }

        dfs_vec.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + C);

    for (int i = 0; i < C; i++) {
        dfs_vec.push_back(arr[i]);

        if (moeum.find(arr[i]) == moeum.end()) {
            dfs(0, 0, 1, i + 1);
        } else {
            dfs(0, 1, 0, i + 1);
        }

        dfs_vec.pop_back();
    }
}
