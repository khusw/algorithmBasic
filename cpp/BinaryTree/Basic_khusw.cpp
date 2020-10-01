/*
    이진 트리(Binary Tree)
    비 선형 자료구조의 대표적 예제.
    데이터 탐색 속도를 증진 시키기 위해 사용되는 자료구조.
    트리를 제대로 구현하려면, Pointer 를 사용해야 노드간 연결이 가능함.

    이진 트리의 탐색 속도가 빠른 것은
    절반씩 탐색을 하기 때문이다.
    이진 탐색 자체가 반 나누고 작은거 왼쪽 큰거 오른쪽 하는 식으로 
    탐색을 하기 때문이다.
    log2N 으로 탐색

    이진 트리에서 포인터를 쓰는 이유는 
    이진 트리가 항상 complete binary tree 가 아니기 때문이다.
    완전 이진 트리의 경우 위에서 부터 순서대로 배열 index 번호를 할당해서 
    노드를 정렬 할 수가 있지만,
    그 외의 이진 트리에서는 이런 인덱스 부여가 곤란하기 때문 
    (참고로 힙 정렬 할 때는, 완전 이진 트리라고 가정한 상태에서 정렬하므로 배열로만 처리 가능)
    예를 들면, 노드가 4개인데 모두 우측으로만 나열되어 있다고 치면
                    0
                1       2
            3   4       5   6
        7   8   9       10  11  12
    노드 4개가 모두 우측으로 배열 되어 있으면, 
    0, 2, 6, 12 번째에 노드가 부여된것. 만약 이것을 배열로써 위에서 부터 인덱스를 부여해서 처리한다면,
    배열의 크기는 13이되고 9개는 쓰지 않는 데이터가 되버려서 메모리 낭비가 됨.
    그래서 노드에 포인터를 달아서 다른 노드를 가르키도록 하게 하면, 메모리 낭비도 줄일 수 있음.

    
    - 이진 트리에서 데이터를 탐색하는 3가지 방법
    1. 전위 순회(Preorder Traversal)
    위 - 왼 - 오
    2. 중위 순회(Inorder Traversal)
    왼 - 위 - 오
    3. 후위 순회(Postorder Traversal)
    왼 - 오 - 위

    아래의 코드는 배열이 아닌 포인터를 사용해서 이진트리를 구현하는 코드임
*/

#include <iostream>

using namespace std;

int number = 15;

// 구조체 (클래스 = 구조체 + 함수)
// 하나의 노드 정보를 선언하기 위한 구조체 선언
typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} node;

// 전위 순회(Preorder) 를 구현한 코드
void preorder(treePointer ptr)
{
    if (ptr)
    {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// 중위 순회(Inorder) 를 구현한 코드
void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        cout << ptr << ' ';
        inorder(ptr->rightChild);
    }
}

// 후위 순회(Postorder) 를 구현한 코드
void postorder(treePointer ptr)
{
    if (ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr << ' ';
    }
}

/*
    위의 세가지 순회 방법에서 
    단순한 출력 부분은 위 노드를 의미함
    (왼쪽노드, 오른쪽 노드는 leftChild, rightChild 로 표현)
*/

int main()
{
    node nodes[number + 1];
    for (int i = 1; i <= number; i++)
    {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    // 위 반복문은 초기화 작업

    for (int i = 1; i <= number; i++)
    {
        if (i % 2 == 0) // 짝수번째 노드이면
        {
            nodes[i / 2].leftChild = &nodes[i];
        }
        else // 홀수번째 노드이면
        {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }

    preorder(&nodes[1]); // 1 번노드를 기준으로 전위순회 테스트
}