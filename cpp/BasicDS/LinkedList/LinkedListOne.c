/*
    Linked List in C
*/

#include <stdio.h>
#include <stdlib.h> // 동적 할당

typedef struct
{
    int data;
    struct Node *next;
} Node;

Node *head; // 첫 시작 노드를 전역 변수로 선언

void addFront(Node *root, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root)
{
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void freeAll(Node *root)
{
    // 이 코드의 문제는 head 를 할당 해제 하지 않는 다는 것.
    Node *cur = head->next; // 헤드 다음 포인터
    while (cur != NULL)
    { // 다음 노드가 존재하면
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root)
{
    Node *node = root->next;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    addFront(head, 1);
    addFront(head, 2);
    addFront(head, 4);
    addFront(head, 7);
    addFront(head, 3);
    addFront(head, 6);

    removeFront(head);

    showAll(head);
    freeAll(head);

    system("pause");
    return 0;
}

/*
    실질적 연결리스트 삽입 삭제는
    더 많은 예외처리가 필요한 경우가 있음

    1. head 자체가 없는 경우
    2. 중간 노드 삭제 삽입에 대한 처리가 필요함.

    배열에 비해 삽입 삭제는 간단하나,
    특정 인덱스로 배열처럼 즉시 접근 불가능하고,
    반드시 원소를 순차적으로 검색해야 하며,
    메모리가 유동적임.
*/