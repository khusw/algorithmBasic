/*
    Segment Tree 란 
    여러개의 데이터가 연속적으로 존재할때, 특정 범위의 데이터 합을 구하는 방법이다.
    예를 들면, 배열이 주어졌을때, 배열 일부 구간의 합을 가장 빠르게 구하는 방법 등 이 있다.

    배열 데이터가 5 8 7 3 2 5 1 8 9 8 7 3 이 있다고 하면,
    인덱스 1 ~ 10 까지의 합을 구하라하면,
    각 인덱스 값 하나하나를 더하면 된다.
    즉, 연산속도가 O(N) 인 것.
    근데 배열 데이터 갯수가 많아지면 연산의 속도가 느려지므로
    이를 더 빨리 할수있는 방법을 찾으면,
    트리 구조를 활용한다.

    트리는 구조상 두 개씩 나뉘기 때문에 logN 을 소요해서 연산하도록 하는게 가능하다
    
    만약 이를 트리로 나타낸다면
    먼저 입력으로 1 9 3 8 4 5 5 9 10 3 4 5 가 주어졌다고 하면,
    이를 가지고 구간일부의 합을 갖는 구간 합 트리를 표현한다.

    구간 합 트리의 루트 노드는 모든 입력값의 합을 나타내며
    이때 값은 66 이다
    루트노드 66 의 바로 직계 자손 노드 두개는
    왼쪽 자식노드는 인덱스 0 ~ 인덱스 5 까지의 구간합이고,
    오른쪽 자식노드는 인덱스 6 ~ 인덱스 11 까지의 구간합이다.

    왼쪽 자식노드의 자식노드들은 0 ~ 2 까지가 좌측, 3 ~ 5 까지가 우측으로 또 반씩 나뉜다
    이렇게 쭉 계속 나뉘면서 구간합 트리를 나타낸다

    다만 주의할 것은 구간 합 트리의 인덱스 번호는 1 부터 시작한다.
    2를 곱했을 때, 2의 배수가 왼쪽 자식 노드에 붙도록 설정하기 위해서이다.

    구현의 간편성 측면에서는 재귀함수를 사용하는 것이 더 좋다.


    참고
    https://blog.naver.com/ndb796/221282210534
*/

#include <iostream>
#include <vector>
#define NUM 12

using namespace std;

int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5}; // 초기 입력값
int tree[4 * NUM]; // 구간합 트리

int init(int start, int end, int node)
{
    // 구간 합 트리 초기화 작업
    // 재귀함수로 구현하게 되면 이는 top-down approach 방식이다.
    if (start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
    // 구간 합 을 구하는 함수
    // left 와 right 는 구하고자 하는 구간합의 범위를 지정하는 것. (구간합의 인덱스 번호가 아니라, 배열의 일부 인덱스 번호를 의미함)
    // start 와 end 는 입력 배열의 첫 인덱스 부터 끝 인덱스 까지를 의미함. 
    // node 는 트리 노드의 인덱스 번호를 의미함.
    if (left > end || right < start) return 0; // 범위 밖
    if (left <= start && end <= right) return tree[node]; // 범위 안
    // 아래 처럼 구간을 둘로 쪼개는 것은 범위에 속하긴 하는데 한개의 노드에서 모든것을 표현할 수는 없고
    // 부분이 짤려서 다른 곳에 있는 경우가 해당한다.
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif)
{
    // start 와 end 는 각각 시작과 끝 인덱스를 의미하며,
    // index 는 구간합을 수정하고 싶은 노드 번호를 의미하며,
    // dif 는 수정할 값을 의미함
    // 5번의 수를 -1 로 바꾸고 싶다하면, index = 5, dif = -1 임.
    if (index < start || index > end) return;
    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
    init(0, NUM - 1, 1);
    cout << "0부터 12까지 합 : " << sum(0, NUM - 1, 1, 0, 12) << '\n';
    cout << "3부터 8까지의 합 : " << sum(0, NUM - 1, 1, 3, 8) << '\n';
    cout << "인덱스 5의 원소를 -5로 수정" << '\n';
    update(0, NUM - 1, 1, 5, -5);
    cout << "3부터 8까지의 합 : " << sum(0, NUM - 1, 1, 3, 8) << '\n';
    return 0;
}