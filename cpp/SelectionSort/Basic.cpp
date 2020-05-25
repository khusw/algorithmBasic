#include <iostream>

using namespace std;

int main()
{
    int i, j, min, index, temp; // i,j 는 반복문 인덱스, min 은 최소값, index 는 최소값의 인덱스, temp 는 swap 을 위한 값
    int arr[10] = {1, 5, 10, 2, 3, 7, 8, 9, 4, 6};
    for (i = 0; i < 10; i++)
    {
        min = 9999;
        for (j = i; j < 10; j++) {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

/*
    선택 정렬의 기본은
    주어진 배열에서 가장 작은 놈을 선택해서 맨 앞으로 보낸다
    그러기 위해선 무조건 for 를 두 번 쓸 수 밖에 없음
    (전체 한 바퀴를 도는 for, 그 안에서 부분 집합으로 도는 for)
*/

/*
    선택 정렬에서의 시간 복잡도는 
    O(n^2) 임
    왜냐, 위에서 10 개를 예로 들었는데,
    10 개 비교시에는 이런식으로 계산 됨
    10 + 9 + 8 + 7 + 6 + 5 + .... + 1 (비교 횟수를 의미)
    이는 등차 수열로
    N * (N + 1) / 2 => O(n^2) 이 된다.
*/