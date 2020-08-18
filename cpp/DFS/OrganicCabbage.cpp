/*
    BOJ 1012 유기농 배추
    https://www.acmicpc.net/problem/1012

    DFS 를 이용해서 푸는 문제로 이동 방향은 상하좌우가 있다.
    상하좌우 네 방향에 다른 배추가 위치해 있다면 인접한 경우이다.
    만약 인접한 배추가 없는 경우 다른 그룹으로 취급한다

    이문제는 DFS 를 이용해서 타 그룹간 분할 시 그룹의 총 갯수를 묻는 문제이다.
*/

#include <cstring>
#include <iostream>
#define MAX 51

using namespace std;

int T, M, N, K;  // T 는 테스트 케이스, M 은 가로 길이, N 은 세로 길이, K 는 배추위치 갯수
int checked[MAX][MAX];
int adj[MAX][MAX];
int dx[4] = {0, 0, -1, 1};  // 상하좌우
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    checked[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int new_x = dx[k] + x;
        int new_y = dy[k] + y;
        if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N)) {
            if (adj[new_x][new_y] == 1 && !checked[new_x][new_y]) {
                dfs(new_x, new_y);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(checked, 0, sizeof(checked));
        memset(adj, 0, sizeof(adj));

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][j] == 1 && !checked[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}