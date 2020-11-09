/* 
    BOJ 11866 요세푸스 문제 0
    https://www.acmicpc.net/problem/11866
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, k;
queue<int> q;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) q.push(i);

    cout << "<";
    while (!q.empty()) {
        for (int i = 0; i < k - 1; ++i) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if (!q.empty()) cout << ", ";
    }
    cout << ">" << endl;

    return 0;
}