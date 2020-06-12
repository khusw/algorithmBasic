/*
    0/1 Knapsack Algorithm

    배낭 채우기 알고리즘

    예를 들면, 어떤 사람이 배낭을 가지고 있고,
    그 배낭의 무게가 17 일때,
    주어진 아이템들의 무게와 가치 테이블이 다음과 같이 주어진다 하면,
    index   |   weight  |   value
      0     |      5    |     8
      1     |      8    |    11
      2     |      3    |    3
      3     |      4    |    6
      4     |      2    |    4
      5     |      6    |    9

    배낭의 크기에 맞춰서 최대의 가치를 뽑아낼 수 있도록 아이템들을 넣는 방법은?

    이런 문제가 바로 배낭 채우기 알고리즘이다.
    단순히 무게만 따져서, 가벼운 순서대로 많이 넣는 것이 아니라,
    가치 값을 고려해야함
    무게만 따져서 가벼운 순으로 넣는다 치면,
    2,3,4,5 의 무게 일 때 무게의 합 14 가 되고 그때의 가치 값은 21 이다
    근데, 무게가 8, 6, 2 인 물건들 넣고 가치를 따져보면, 24 가 된다
    이렇게 맞지 않는 경우가 반드시 존재한다.
    그러므로, 단순히 무게만 따져선 안되는 것이고,
    물건을 넣었을 때, 배낭의 남은 무게와 물건들의 가치값을 종합적으로 비교해서 넣어야 
    원하는 결과를 얻을 수 있는 것이다.
*/

#include <stdio.h>
#define W 0
#define V 1
#define N 6
#define MAX(a, b) a > b ? a : b;

// 초기 아이템 테이블을 표현한 이차원 배열
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
    // pos 는 아이템의 위치 인덱스
    // capacity 는 배낭의 남은 용량을 표현한다.
    if (pos == N)
        return 0; // 6이라는 것은 모든 인덱스를 다 돌았음을 의미함

    int re = 0;
    if (items[pos][W] <= capacity)
    {
        re = knapsack(pos + 1, capacity - items[pos][W]) + items[pos][V];
    }
    re = MAX(re, knapsack(pos + 1, capacity));
    return re;
}

int main()
{
    int capacity = 17;
    printf("knapsack(%d, %d)=$d\n", 0, capacity, knapsack(0, capacity));
    return 0;
}