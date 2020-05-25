/*
    Basic.cpp 에서 작성한 quick sort 를 
    오름차순 정렬이 아니라, 내림 차순 정렬로 수행되는 코드를 작성.
    (두개의 부분만 바꾸면 내림차순으로 바꿀 수 있음.)
*/

/*
    어떻게 바꾸는가
    퀵 정렬은 pivot 보다 작은것이 왼쪽,
    큰 것이 오른쪽으로 가게 했기 때문에
    내림 차순으로 하려면, 작은 것이 오른쪽, 큰 것이 왼쪽에 오게 하면된다.
*/

#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j)
    {
        // i 와 j 의 인덱스가 서로 엇갈릴 때 까지 반복
        while (data[i] >= data[key])
        {
            i++;
        }
        while (data[j] <= data[key] && j > start)
        {
            j--;
        }
        if (i > j)
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main()
{
    int num = 10;
    int data[10] = {1, 5, 7, 8, 2, 3, 9, 10, 4, 6};
    quickSort(data, 0, num - 1);
    for (int i = 0; i < num; i++)
    {
        cout << data[i] << ' ';
    }
    return 0;
}