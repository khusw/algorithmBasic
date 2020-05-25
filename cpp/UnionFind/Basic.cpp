/*
    합집합 찾기(Union Find) 알고리즘
    그래프 알고리즘 관련 대표적인 예시로,
    서로소 집합 알고리즘(Disjoint-Set Algorithm) 
    이라고도 불린다.

    여러개의 노드가 존재할때, 두개의 노드를 선택해서
    이 두 노드가 서로 같은 그래프에 속하는지 판별. 

    먼저 노드가 주어지고,
    각 노드 번호의 값으로는 부모 노드의 값이 들어감 (연결된 노드의 노드 번호를 가짐)
    예를 들어서, 1,2 노드가 서로 연결되었다면,
    1,2 인덱스의 값은 1 이 됨(더 작은 인덱스 값을 기준으로 value 가 부여됨.)
    이렇게 인덱스 값을 더 작은 것으로 부여하는 것을 Union(합침) 이라고 부른다.

    나동빈 블로그 그림을 보면 알겠지만,
    인덱스 3이 2와 연결될 경우 인덱스 3 의 값이 2로 바뀜
    근데 1-2-3 이런식으로 서로 연결 되어 있고,
    가장 작은 노드 번호는 1 이기 때문에 
    인덱스 3 의 값은 1로 바뀌어야함.
    이런 문제를 개선하려면, 3의 부모의 부모 를 찾아가게 하도록
    재귀함수를 통해서 이 문제점을 개선해야함.
    (이때 사용되는 함수가 Union)
    즉, Union-Find 알고리즘은 두 노드의 부모 노드를 확인하여, 현재 같은 집합에 속하는지 확인하는 알고리즘이라 할 수 있다.
*/

#include <stdio.h>

// 부모 노드를 찾기 위한 함수
int getParent(int parent[], int x)
{
    if (parent[x] == x)
        return x; // 재귀함수의 종료 선언문
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a); // a 의 부모노드 찾아서 a 로 리턴
    b = getParent(parent, b); // b 의 부모노드 찾아서 b 로 리턴
    if (a < b)
        parent[b] = a; // 더 작은 값이 들어가도록 배열 값을 수정하는 조건문.
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 = 같은 그래프에 속하는지를 확인하는 함수
int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}

int main()
{
    int parent[11];
    for (int i = 1; i <= 10; i++)
    {
        parent[i] = i; // 초기에 자기자신을 부모로 삼는 것.
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    printf("1 과 5 는 연결되어 있는가 ? %d\n", findParent(parent, 1, 5));
    unionParent(parent, 1, 5);
    printf("1 과 5 는 연결되어 있는가 ? %d\n", findParent(parent, 1, 5));
    return 0;
}

/*
    이 union-find 알고리즘은
    나중에 크루스칼 알고리즘 등에 사용되는
    기반이 되는 알고리즘이므로 반드시 익히고 있어야함.
*/