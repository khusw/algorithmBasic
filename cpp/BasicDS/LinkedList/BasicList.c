/*
    배열을 활용한 기본 리스트 구현
*/

#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0; // 갯수 카운팅

void addBack(int data)
{
    arr[count] = data;
    count++;
}

void addFirst(int data)
{
    for (int i = count; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
    count++;
}

void deleteAt(int index)
{
    for (int i = index; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    count--;
}

void show()
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    addBack(10);
    addBack(20);
    addBack(30);
    addFirst(15);
    addFirst(17);
    system("pause");
    return 0;
}

/*
    배열 기반의 리스트는
    위에 보는 것 처럼,
    1. 배열을 위한 메모리 할당 크기가 고정적이다.
    2. 중간에 값을 추가, 삭제하는 것이 전체 구조를 재정렬 해야 되기 때문에 
    상당히 비효율적이다.

    배열의 단점을 극복한게 LinkedList 다.
    Linked List 는 포인터를 활용한다.
    구조체와 포인터를 이용해서 구현하며, 필요할 때마다 메모리 할당 가능
    
*/