/*
    BOJ 15684 사다리 조작
    https://www.acmicpc.net/problem/15684
*/

#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

int n, m, h, answer = INF;
int adj[11][31];
bool visited[11][31];

bool is_valid() {
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        for (int j = 1; j <= h; ++j) {
            if (visited[temp][j])
                temp += 1;
            else if (visited[temp - 1][j])
                temp -= 1;
        }
        if (temp != i) return false;
    }
    return true;
}

void recursion(int idx, int depth) {
    if (depth >= 4) return;

    if (is_valid()) {
        answer = min(answer, depth);
        return;
    }

    for (int i = idx; i <= h; ++i) {
        for (int j = 1; j < n; ++j) {
            if (visited[j][i]) continue;
            if (visited[j - 1][i]) continue;
            if (visited[j + 1][i]) continue;

            visited[j][i] = true;
            recursion(i, depth + 1);
            visited[j][i] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        visited[b][a] = true;
    }

    recursion(1, 0);

    if (answer == INF) answer = -1;
    cout << answer;

    return 0;
}