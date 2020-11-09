/*
    BOJ 1406 에디터
    https://www.acmicpc.net/problem/1406
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

string str;
int M;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> str;
    cin >> M;

    list<char> editor(str.begin(), str.end());
    auto cursor = editor.end();

    while (M--) {
        char order, ch;
        cin >> order;
        if (order == 'L') {
            if (cursor != editor.begin())
                cursor--;
        } else if (order == 'D') {
            if (cursor != editor.end())
                cursor++;
        } else if (order == 'B') {
            if (cursor != editor.begin())
                cursor = editor.erase(--cursor);
        } else if (order == 'P') {
            cin >> ch;
            editor.insert(cursor, ch);
        }
    }

    for (auto& iter : editor) cout << iter;

    return 0;
}