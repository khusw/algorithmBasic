/*
    Segment Tree 를 Bottom-Up 방식으로 표현.
*/

#include <iostream>

using namespace std;

int N = 6;
int capacity;  // 리프 노드의 갯수를 의미한다
int* tree;

void build_tree() {
    int data[] = {1, 2, 3, 4, 5, 6};
    for (capacity = 1; capacity < N;)
        capacity *= 2;             // N 보다는 큰 2의 제곱수가 되도록 설정한다.
    tree = new int[capacity * 2];  // 구간 합 트리 변수를 생성한다.

    int cnt = 0;                                                          // cnt 는 data 배열에 대한 인덱스 번호 역할을 한다.
    for (int i = capacity; i < capacity + N; i++) tree[i] = data[cnt++];  // 리프노드에 해당하는 부분에 값을 넣는다.
    for (int i = capacity + N; i < capacity * 2; i++) tree[i] = 0;        // 마지막 레벨의 리프 노드들 중 해당하지 않는 것은 0 으로 초기화
    for (int i = capacity - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    // capacity - 1 인 것은 완전이진트리 이기 때문에, 리프노드의 갯수 - 1 이 나머지 노드 갯수다.
    // 또한 이 반복문은 부모 노드들에 대한 초기화 작업이다.
}

void update(int index, int data) {
    int k = capacity + index;                                          // 리프노드의 시작점이 capacity 이므로 이를 기준으로 index 를 더한 지점이 변경지점이 되야 한다.
    tree[k] = data;                                                    // 데이터 변경
    for (k /= 2; k > 0; k--) tree[k] = tree[k * 2] + tree[k * 2 + 1];  // 상위 노드로 올라가면서 변경할 대상들을 찾고 변화
    // update 함수의 시간 복잡도는 O(NlogN) 이다. (탐색이 O(logN), N 개의 데이터 여서 O(N))
}

int query(int L, int R) {
    int ret = 0;
    L += capacity;
    R += capacity;
    for (; L < R; L /= 2, R /= 2) {      // 아래의 두 조건을 만족하지 않는 경우는 상위 노드가 필요한 경우임
        if (L % 2) ret += tree[L++];     // L % 2 == 1, 우측 자식 노드인 경우 (상위 노드가 필요 없음)
        if (!(R % 2)) ret += tree[R--];  // R % 2 == 0, 좌측 자식 노드인 경우 (상위 노드가 필요 없음)
    }
    if (L == R) ret += tree[L];  // L == R 이면 해당 노드의 값을 최종값 ret 에 더해서 합산
    return ret;
}

int main() {
    build_tree();

    cout << "인덱스 2,5 사이의 구간합" << query(2, 5) << '\n';

    update(3, -4);

    cout << "인덱스 2,5 사이의 구간합" << query(2, 5) << '\n';

    delete[] tree;
    return 0;
}