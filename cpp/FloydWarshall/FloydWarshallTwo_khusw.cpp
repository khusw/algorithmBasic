/*
    이 폴더의 Basic.cpp 와 마찬가지로 Floyd Warshall 알고리즘을 쓰지만,
    Basic 은 최단 경로의 가중치 값을 구했다면,
    여기서는 최단 경로에 해당하는 노드 순서를 표현하기 출력하기 위한 알고리즘임

    이차원 배열 W, D 이외에, P 라는 이차원 배열을 새로 생성함
    이 P 는 vi 에서 vj 로 갈때 최단 경로 중간에 놓여 있는 정점 중 가장 큰 인덱스 값을 저장함

*/

#include <stdio.h>
#define number 5
#define INF 1000000

int W[number][number] = {
    {0, 1, INF, 1, 5},
    {9, 0, 3, 2, INF},
    {INF, INF, 0, 4, INF},
    {INF, INF, 2, 0, 3},
    {3, INF, INF, INF, 0}}; // 5*5 인접행렬 W
int P[number][number];      // 중간 노드 번호 값을 저장할 이차원 배열
int D[number][number];      // 최단 가중치 값을 저장하는 이차원 배열

void path(int x, int y)
{
    if (P[x][y] != 0)
    {
        path(x, P[x][y]);
        printf("v%d", P[x][y]);
        path(P[x][y], y);
    }
}

void floydWarshall(int x, int y) // x -> y 사이의 경로를 표현
{
    // D(0) = W 이므로 초기화 선언 필요
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            D[i][j] = W[i][j];
        }
    }

    for (int k = 0; k < number; k++)
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                // k 는 중간 노드의 번호이며,
                // i 는 시작 노드의 번호,
                // j 는 끝 노드의 번호를 의미함
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // 위에는 최단경로를 지정하는 것이라면,
    // 아래는 최단 경로와 중간 노드를 출력하기 위한 이중 포문
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            printf("%3d ", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            printf("%3d ", P[i][j]);
        }
        printf("\n");
    }

    path(x, y);
}

int main()
{
    floydWarshall(5, 3);
    return 0;
}