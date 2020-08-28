/*
    BOJ 7576 토마토
    https://www.acmicpc.net/problem/7576

    BOJ 1697 과 유사한 문제유형.
    기본 BFS 에 추가적으로 몇가지를 더 할 수 있어야 풀 수 있는 문제.
*/

#include <iostream>
#include <queue>
#include <utility>
#define MAX 1001

using namespace std;

int M, N, answer;
int adj[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_y = y + dy[i];
            int new_x = x + dx[i];
            if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N) && adj[new_y][new_x] == 0) {
                adj[new_y][new_x] = adj[y][x] + 1;
                q.push({new_y, new_x});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N;  // 가로 세로 입력 (입력이 가로,세로 인것은 각각 열의갯수, 행의 갯수를 의미함, x,y 가아니라 y,x 란뜻)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) {
                q.push({i, j});  // 초기의 익은 토마토만 큐에 넣기 위함 (y,x) 를 넣음
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (adj[i][j] == 0) {
                // 하나라도 익지 않았다면 익을수 없는 토마토 상자라는 의미
                cout << "-1" << '\n';
                return 0;
            }

            if (answer < adj[i][j]) {
                answer = adj[i][j];
            }
        }
    }

    // 토마토 배열의 값이 1부터 시작하므로 1을 빼야 맞음.
    cout << answer - 1 << '\n';

    return 0;
}