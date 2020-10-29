/*
    BOJ 1389 케빈 베이컨의 수
    https://www.acmicpc.net/problem/1389
*/

#include <bits/stdc++.h>

#define MAX 100

using namespace std;

int N, M;
int adj[MAX][MAX];
int connect[MAX];    // 출발 지점 부터 각 노드간 연결 단계수를 표현하는 배열
int resultBFS[MAX];  // connect 의 합을 담는 배열
bool visited[MAX];   // 방문 여부

int minConnect() {
    int minNum = resultBFS[1];
    int minIdx = 1;
    for (int i = 2; i <= N; ++i) {
        if (minNum > resultBFS[i]) {
            minNum = resultBFS[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (adj[x][i] == 1 && visited[i] == false) {
                visited[i] = true;
                q.push(i);
                connect[i] = connect[x] + 1;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1, adj[b][a] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        bfs(i);
        for (int j = 1; j <= N; ++j) {
            resultBFS[i] = resultBFS[i] + connect[j];
        }
        memset(visited, false, sizeof(visited));
        memset(connect, 0, sizeof(connect));
    }

    cout << minConnect() << "\n";

    return 0;
}