/*
    BOJ 2751 수 정렬하기 2
    https://www.acmicpc.net/problem/2751
    이 문제 같은 경우 2750 과 다른 점은 
    입력의 갯수가 총 백만개가 들어올 수 있다는게 차이점임.

    맨 첫번째 입력에 총입력 갯수가 주어지고, 두번째 입력 부터는 입력되는 실제 값이 들어옴.
    이를 오름차순으로 정렬하는 문제인데,
    앞에서도 살펴봤지만, 선택정렬, 버블정렬, 삽입정렬의 경우 O(n^2) 가 걸림을 알 수 있음
    그래서 이렇게 백만개나 들어올 수 있는 상황에서는 시간제한을 반드시 초과하게 되어 있음
    그래서 여기서는 퀵 정렬을 사용해야 함.
*/

#include <stdio.h>

void quickSort(int *data, int start, int end) {
    int key = start;    // 시작 인덱스
    int i = start + 1;  // 맨 앞 바로 다음 인덱스
    int j = end;        // 마지막 번째 인덱스
    int temp;           // swap 을 위한 변수

    if (start >= end)  // start 가 end 보다 크거나 같다는 것은 원소의 갯수가 1개 라는뜻.
    {
        return;
    }

    while (i <= j)  // 엇갈리는 상태가 되기 전까지 계속 반복
    {
        while (data[i] <= data[key])  // 큰 값을 찾을 때 까지 이므로 key 가 더 클때 i++
        {
            // 좌측 부분 배열에 대한 인덱스 찾기
            // 오름 차순 정렬이므로, pivot 보다 큰 값을 찾을 때까지 i 인덱스를 늘림
            i++;
        }
        while (data[j] >= data[key] && j > start)  // 키 보다 작은 값을 찾을 때 까지 이므로 key 가 더 작을 때 j--
        {
            // 우측 부분 배열에 대한 인덱스 찾기
            // 우측 부분 배열이므로 pivot 보다 작은 값을 찾을 때까지 j 인덱스를 줄임
            // 추가적으로 j 가 start 보다 작아지면 안되므로, j > start 조건을 달아야함.
            j--;
        }
        if (i > j)  // 엇갈린 상황.
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else  // 엇갈린 상황이 아니므로, key 와 swap 인게 아니라, i 와 j 번째를 swap
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main() {
    int N;
    scanf("%d", &N);
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    delete[] arr;
    return 0;
}

/*
    항상 입력이 백만 이상이 된다 하면
    무조건 N logN 인 병합정렬 퀵정렬 힙정렬을 사용해야만 답으로 인정 받을 수 있음.
    근데, 퀵 정렬은 최악의 경우 O(n^2) 가 될 수 도 있기 때문에,
    백만이상의 입력이 들어오는 경우, 병합정렬 힙정렬을 사용하는게 더 도움됨.
    일단 5/15일 기준 여기까지 배운 것은 퀵 정렬이므로 퀵정렬을 사용해야함.
*/

/*
    BOJ 에서 런타임 에러로 처리되는거 보니까
    아마도 퀵정렬로는 처리가 안되는거 같음
    그러므로, 앞으로 배우게 될 병합정렬, 힙 정렬을 통해서 문제를
    다시 풀도록해라.

    그리고 실전에서는 일일이 쓰지 말고
    STL sort 를 사용해서 정렬하는것이 속편할때가 많음.
*/