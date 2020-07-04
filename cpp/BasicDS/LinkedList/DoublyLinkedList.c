/*
    양방향 연결 리스트 구현

    맨 앞을 Head, 맨 뒤를 Tail 이라 부름

    이 doubly linked list 는 prev, next 라는 두개의 포인터가 필요
*/
#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List 에 쓰일 Node.
typedef struct
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail; // 맨 앞, 뒤 노드 선언

void removeFront()
{
    Node *node = head->next;
    head->next = node->next;
    Node *next = node->next;
    next->prev = head;
    free(node);
}

void insert(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    Node *cur; // node 의 포인터 역할
    cur = head->next;
    while (cur->data < data && cur != tail)
    {
        cur = cur->next;
    }

    Node *prev = cur->prev;
    prev->next = node;
    node->prev = prev;
    cur->prev = node;
    node->next = cur;
}

void showAll()
{
    Node *cur = head->next;
    while (cur != tail)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void)
{
    head = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;

    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);

    removeFront();
    showAll();

    return 0;
}
