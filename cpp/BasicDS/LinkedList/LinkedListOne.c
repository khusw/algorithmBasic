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

Node *head;

int main()
{
    head = (Node *)malloc(sizeof(Node));

    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->data = 10;

    head->next = node1;

    Node *node2 = (Node *)malloc(sizeof(Node));
    node2->data = 20;

    node1->next = node2;

    Node *cur = head->next; // 포인터 역할
    while (cur != NULL)
    { // 처음 노드 부터 끝 노드 까지 순회
        printf("%d", cur->data);
        cur = cur->next;
    }

    free(head);
    free(node1);
    free(node2);

    system("pause");
    return 0;
}