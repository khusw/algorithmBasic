/*  
    BOJ 11724 연결 요소의 갯수
    https://www.acmicpc.net/problem/11724
*/

#include <iostream>
#define MAX 1001

using namespace std;

int adj[MAX][MAX];
int checked[MAX];
int N, M, cnt;

void dfs(int x) {
    checked[x] = true;
    for (int i = 1; i <= N; i++) {
        if (!checked[i] && adj[x][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!checked[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}