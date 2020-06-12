/*
    DP 를 이용한 배낭 채우기 알고리즘
    아이템의 양이 무한정 늘어 났을 때, 배낭 채우기 알고리즘을 쓸때,
    재귀함수로 구현을 하므로, 메모리 상의 문제가 발생할 수 있으므로,
    DP 를 사용해서 메모이제이션을 한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define W 0
#define V 1
#define N 6
#define MAX_CAPCITY 1000
#define MAX(a, b) a > b ? a : b;

int dp[N][MAX_CAPCITY];
int items[N][2] = {
    {5, 8},
    {8, 11},
    {3, 3},
    {4, 6},
    {2, 4},
    {6, 9},
};

int knapsack(int pos, int capacity)
{
    if (pos == N)
        return 0;

    int re = dp[pos][capacity];

    if (re != -1)
        return re;

    if (items[pos][W] <= capacity)
    {
        re = knapsack(pos + 1, capacity - items[pos][W]) + items[pos][V];
    }

    re = MAX(re, knapsack(pos + 1, capacity));

    return dp[pos][capacity] = re;
}

int main()
{
    int capacity = 17;
    memset(dp, -1, sizeof(dp));
    printf("knapsack(%d, %d)=%d\n", 0, capacity, knapsack(0, capacity));
    return 0;
}
