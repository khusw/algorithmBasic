/*
    BOJ 2178 미로 탐색

    https://www.acmicpc.net/problem/2178

    N * M 크기의 미로가 주어지며, 미로 내부의 값은 0, 1 로만 구성되어 있다.
    1 은 이동가능한 칸, 0은 이동 불가능한 칸이다.
    첫 시작위치는 (0,0) 이 아니라 (1,1) 이다.
    (1,1) 에서 출발해서 (N,M) 의 위치로 이동하기 위한 최소 이동 칸의 갯수를 구하는 프로그램을 작성해야 한다.
    칸 이동시에는 서로 인접한 칸만 이동 가능하다 라는것을 봐서는 대각선 이동은 불가능하며,
    상하좌우 방향으로만 이동이 가능하다.
    이동 칸의 갯수를 셀때, 시작 칸과 도착위치 칸 도 갯수로 포함시켜야 한다.

    입력 N, M 은 (2 ~ 100) 까지의 수 이며
    출력은 최소 칸수를 출력해야한다.

*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
string adj[101];
int sum[101][101];
int checked[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    checked[i][j] = true;
    sum[i][j] = 1;
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if ((0 <= newX && newX < N) && (0 <= newY && newY < M))
            {
                if (adj[newX][newY] == '1' && !checked[newX][newY])
                {
                    checked[newX][newY] = true;
                    q.push({newX, newY});
                    sum[newX][newY] = sum[x][y] + 1;
                }
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> adj[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (adj[i][j] == '1' && !checked[i][j])
            {
                bfs(i, j);
            }
        }
    }

    cout << sum[N - 1][M - 1];

    return 0;
}

/*
    처음에 이문제를 DFS 로 풀려고 했으나, DFS 로 최단거리 문제를 풀때는 시간 초과의 오류가 발생한다고 한다.
    DFS 는 끝까지 전체를 다 탐색하고 돌리는 방식이어서 (스택 메모리를 생각해봐도 어쩔수 없이 모든 함수를 다 돌아야 함을 알 수 있다)
    시간 초과의 문제가 생긴다고 한다.
    그래서 최단 거리를 찾아라 이러면 무조건 BFS 를 써야겠구나 생각하면 된다.
*/