/*
    BOJ 1182 부분수열의 합 (use backtracking)
    https://www.acmicpc.net/problem/1182
*/

#include <iostream>

using namespace std;

int N, S, val[20];
int cnt, curSum;

void dfs(int cur) {
    if (cur == N) return;

    if (curSum + val[cur] == S) cnt++;

    dfs(cur + 1);

    curSum += val[cur];
    dfs(cur + 1);

    curSum -= val[cur];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> val[i];
    dfs(0);
    cout << cnt << "\n";

    return 0;
}
