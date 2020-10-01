/*
    이분 검색 (Binary Search) 의 가장 기본 알고리즘 구현
*/

#include <stdio.h>

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main()
{

    int low, high, mid, location, x; // 전부 인덱스 값임
    // location 은 찾으려는 대상 의 인덱스
    // x 는 찾으려는 대상의 값
    scanf("%d", &x);
    low = 0;
    high = 9;
    location = 0;

    while (low <= high && location == 0)
    {
        mid = (low + high) / 2; // 중간 인덱스
        if (x == arr[mid])      // x 를 찾았을 때
            location = mid;     // location 은 찾은 인덱스번호로 교체
        else if (x < arr[mid])  // x 가 중간값보다 작은 위치에 있는 경우
            high = mid - 1;     // high 를 중간-1 번째 인덱스로 지정
        else                    // x 가 중간값보다 큰 위치에 있는 경우
            low = mid + 1;      // low 를 중간+1 번째 인덱스로 지정
    }
    printf("x 의 위치는 ");
    printf("%d", location);
    return 0;
}

/*
    이분 검색 Binary Search 에 대한 시간 복잡도는?
    n 개의 원소가 들어있는 리스트를 1개가 될때까지 분할해서 비교연산을 하므로
    O(logn + 1) 이라 할 수 있으며,
    빅오 표기법에 의하여 O(logN) 이라 할 수 있다.
*/