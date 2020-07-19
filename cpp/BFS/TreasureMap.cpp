/*
    보물섬 (BOJ 2589)
    https://www.acmicpc.net/problem/2589

    보물 지도가 주어지고, 보물지도에는 L(육지), W(바다) 로 데이터가 적혀 있다.

    입력으로 보물지도의 세로, 가로 값이 주어지며,
    다음 줄 부터는 LW 로 구성된 인접행렬이 주어진다.

    L 그룹에서 보물이 묻힌 두 L 간의 최단 거리를 구하는 문제

    내가 생각하는 이 문제의 핵심은
    1. 좌표값을 가지고 있어야 한다.
    2. queue 를 사용해야 한다.
    3. DFS 보다는 BFS 를 사용해야 풀 수 있다.
    
    최초의 좌표값을 기반으로 같은 그룹 내에서 가장 먼 거리를 계산해야 한다.

*/

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 51

using namespace std;

int initX, initY, maxValue; // 가로, 세로, 최장 거리
string adj[MAX];            // 인접 행렬을 나타내는 배열
int checked[MAX][MAX];      // 방문 여부를 나타내는 배열
int dx[4] = {0, 0, -1, 1};  // 상, 하, 좌, 우
int dy[4] = {1, -1, 0, 0};  // dx 와 같음
int sum[MAX][MAX];          // 거리 합을 담는 변수

void BFS(int i, int j)
{
    queue<pair<int, int>> pos; // 좌표를 담고 있는 큐
    checked[i][j] = true;
    pos.push({i, j});

    while (!pos.empty())
    {
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();

        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if ((0 <= newX && newX < initX) && (0 <= newY && newY < initY))
            {
                if (adj[newX][newY] == 'L' && !checked[newX][newY])
                {
                    checked[newX][newY] = true;
                    pos.push({newX, newY});
                    sum[newX][newY] = sum[x][y] + 1;
                    maxValue = max(maxValue, sum[newX][newY]);
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> initX >> initY;

    for (int i = 0; i < initX; i++)
    {
        cin >> adj[i];
    }

    for (int i = 0; i < initX; i++)
    {
        for (int j = 0; j < initY; j++)
        {
            if (adj[i][j] == 'L' && !checked[i][j])
            {
                BFS(i, j);
                memset(checked, 0, sizeof(checked));
                memset(sum, 0, sizeof(sum));
            }
        }
    }

    printf("%d", maxValue);
    return 0;
}

/*
    이문제에서 주의할 점은
    바로 memset 으로 인한 초기화 작업이 필요하다는 것이다.
    컴퓨터가 이차원 배열을 탐색할 때 
    문제에서 주어진 그림처럼 블록 단위로 알아서 탐색을 하는 것이 아니라,
    (0,0) 지점에서 부터 가로 방향으로 순차적 탐색을 진행하기 때문에
    방문 여부를 다시 초기화 해줘야 하며, 또한 기존에 담고 있었던 거리 계산을 위한 배열인 sum[][] 에 대한 초기화 작업이 필요하다.
    이 문제는 이 memset 을 사용해서 초기화 해주는 것이 핵심 이었다.
    
*/