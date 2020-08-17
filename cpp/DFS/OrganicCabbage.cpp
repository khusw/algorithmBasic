/*
    BOJ 1012 유기농 배추
    https://www.acmicpc.net/problem/1012

    DFS 를 이용해서 푸는 문제로 이동 방향은 상하좌우가 있다.
    상하좌우 네 방향에 다른 배추가 위치해 있다면 인접한 경우이다.
    만약 인접한 배추가 없는 경우 다른 그룹으로 취급한다

    이문제는 DFS 를 이용해서 타 그룹간 분할 시 그룹의 총 갯수를 묻는 문제이다.
*/

#include <iostream>
#define MAX 50

using namespace std;

int T, M, N, K;  // T 는 테스트 케이스, M 은 가로 길이, N 은 세로 길이, K 는 배추위치 갯수
int checked[MAX][MAX];
int adj[MAX][MAX];
int dx[4] = {0, 0, 1, -1};  // 상하좌우
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    checked[y][x] = true;

    for (int k = 0; k < 4; k++) {
        int new_x = dx[k] + x;
        int new_y = dy[k] + y;
        if ((0 <= new_x && new_x < N) && (0 <= new_y && new_y < M)) {
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
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            // 입력이 가로, 세로 순서로 들어옴
            int x, y;
            cin >> x >> y;
            adj[y][x] = 1;
        }
        int cnt = 0;
        // 한가지 주의해야 할 사항은 M 은 가로의 길이가 맞으며, N 은 세로의 길이인것도 맞으나,
        // 가로의 길이가 고정된 상태에서 변하는 것은 세로의 길이이며
        // 세로의 길이가 고정된 상태에서 변하는 것은 가로의 길이이다.
        // 그래서 M, N 의 위치가 바뀌어야 함.
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (adj[x][y] == 1 && !checked[x][y]) {
                    // 이 안에서의 갯수가 그룹의 갯수임
                    // dfs 내에서 ++ 하는 것은 해당 그룹에 속하는 원소의 갯수.
                    dfs(x, y);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}