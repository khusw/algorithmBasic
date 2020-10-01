/*
    BOJ 2752 세 수 정렬
    이 2752 문제는 2750 문제 보다 훨씬 더 쉽다.
    왜냐면 입력이 단 3개만 주어지기 때문이다.
    여태까지 배운 정렬법 삽입정렬, 선택정렬, 버블정렬, 퀵 정렬 그 어느것을 사용해도 답은 나옴
    여기선 한번 버블정렬을 사용해봄

    입력은 숫자 세개가 주어지고, 1 ~ 백만 까지 의 수 임.
    출력은 오름차순으로 전개하면 됨.

    버블 정렬을 사용하려 했으나 문제가 생김
    입력이 만약 예를 들어서
    1000 2500 1 이라 들어오면
    정렬 결과가 1000 1 2500 이 되어버림
    그래서 버블 정렬은 이 문제와는 맞지 않는 듯함
    그래서 선택 정렬로 바꿔서 작성할 것임.
*/

/*
#include <iostream>

using namespace std;

int main()
{
    int arr[3];
    int temp;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /*
                    버블 정렬은 (오름차순 기준) 작은 값을 앞으로 보냄
                    보낼때 양옆을 서로 비교해서 큰놈 오른쪽 작은놈 왼쪽임
                    정렬이 됬든 안됬든 상관하지 않음.
                */
/*
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/

// 선택 정렬을 사용한 경우
#include <stdio.h>

int main()
{

    int min, index, temp; // min 은 최소, index 는 최소값의 인덱스, temp 는 swap 을 위한 변수
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        min = 1000001; // 문제의 조건이 백만 이하의 수가 입력된다 하였음
        for (int j = i; j < 3; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        // swap
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*
    항상 배열의 값에 접근 할 때는 
    &arr[index] 방식으로 접근해야 함
    그리고 c++ 에서도 c 언어의 기능을 그대로 사용할 수 있음
    scanf, prinf 를 사용하고자하는 경우 #include <stdio.h> 를 사용해야하며,
    using namespace std; 는 필요 없게 됨.
    그리고 이 2752 번 문제 처럼, 
    3 1 2 이런 식으로 입력 받고
    출력을 1 2 3 이런 식으로 하는 경우
    cout 을 쓰는 것 보다는 prinf, scanf 를 사용하는게 더 편할 수 있음.
*/