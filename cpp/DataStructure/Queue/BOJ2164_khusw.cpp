/*
    BOJ 2164 카드 2
    https://www.acmicpc.net/problem/2164
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, temp;
queue<int> q;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) q.push(i);

    if (q.size() == 1) {
        cout << q.front() << endl;
        return 0;
    }

    while (true) {
        q.pop();
        temp = q.front();
        if (q.size() == 1) break;
        q.pop();
        q.push(temp);
    }
    cout << temp << endl;
    return 0;
}