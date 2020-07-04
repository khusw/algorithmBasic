/*
    스택

    스택은 FILO 의 자료구조이다.

    연산은 두가지가 존재한다.
    Push, Pop

    스택은 통상 배열을 이용해 구현하거나, 연결 리스트를 이용해 구현함

*/

// 배열을 이용한 스택 구현

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 999999999999

int stack[SIZE];
int top = -1;

void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("stack overflow ! \n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("stack underflow ! \n");
        return -INF;
    }
    return stack[top--]; // 후위 연산자로 하나 줄임으로써 배열 크기 축소와 동시에 값 리턴
}

int main()
{

    return 0;
}