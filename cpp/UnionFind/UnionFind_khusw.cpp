#include <stdio.h>

// 부모 노드를 찾기 위한 함수
int getParent(int parent[], int x) {
    if (parent[x] == x)
        return x;  // 재귀함수의 종료 선언문
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);  // a 의 부모노드 찾아서 a 로 리턴
    b = getParent(parent, b);  // b 의 부모노드 찾아서 b 로 리턴
    if (a < b)
        parent[b] = a;  // 더 작은 값이 들어가도록 배열 값을 수정하는 조건문.
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 = 같은 그래프에 속하는지를 확인하는 함수
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}

int main() {
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;  // 초기에 자기자신을 부모로 삼는 것.
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
