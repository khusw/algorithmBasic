/*
    pivot 을 활용하여 pivot 값 보다 작은 것은 왼쪽
    큰 것은 오른쪽으로 넘기는 방법
    깔끔한 코드 작성을 위해서 재귀 함수를 쓰는 경우가 많다.
*/

#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end)
{
    // start 와 end 는 인덱스 번호를 의미함.
    if (start >= end)
    {
        // start >= end 부분 집합의 원소의 갯수가 1개라는 뜻.
        return;
    }

    int key = start;   // 보통 pivot = key 를 의미하며, 맨 앞을 잡는 경우가 많음.
    int i = start + 1; // i 는 인덱스 번호로 키값 바로 다음것을 첫 인덱스로 잡음
    int j = end;       // j 역시 인덱스 번호로 마지막 것을 잡는다.
    int temp;          // 두 값을 바꾸기 위해 존재하는 임시변수
    // i 는 왼쪽의 출발지점, j 는 오른쪽의 출발지점을 의미.

    while (i <= j)
    {
        // i <= j 라는 것은 '엇갈릴때' 를 의미한다. (노트 참조)
        while (data[i] <= data[key])
        {
            // 왼쪽부터 시작할 경우
            // pivot 보다 큰 값을 찾아야 하기 때문에
            // data[key] 보다 작은 경우 i 의 인덱스를 늘려서 큰값을 찾아내야함.
            i++;
        }
        while (data[j] >= data[key] && j > start)
        {
            // 오른쪽 부터 시작할 경우
            // pivot 보다 작은 값을 찾아야하므로,
            // data[key] 보다 큰 경우 j 의 인덱스를 줄여서
            // 더 작은 값을 찾게 하는 것.
            // 단 주의 할 것은 i 나 j 나 최종에선 하나 더 추가, 감소 해야함.
            // 그리고 j > start 인 것은 j(인덱스) 가 start 보다 아래 인것을 찾으려면
            // 아예 배열 범위를 벗어나게 되어 out of index 가 됨.
            // 왼쪽 범위에서 j > start 같은 조건을 달지 않는 이유는 '엇갈릴때' 전체 while 을 벗어나기 때문.
            j--;
        }
        if (i > j)
        {
            // 엇갈린 상태일때,
            // pivot 값과 data[j] (세모) 를 swap
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            // 엇갈리지 않은 상태일때
            // pivot 보다 큰것, 작은것을 끝까지 돌려서 일단 찾은경우
            // 큰 값(네모), 작은 값(세모) 를 서로 swap
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    // 위의 while(i <= j) 를 나왔다는 것은 서로 엇갈린 상태에 직면한 것이고,
    // 그에 따라서 왼쪽 배열 부분집합과 오른쪽 배열 부분집합 내부에서
    // 자체적인 quickSort 를 수행해야 하므로,
    // 두개의 재귀함수로 선언을함
    // 첫번째에서 j-1 까지 인 이유는
    // 엇갈린 상태에서 j 와 key 가 서로 바뀌기 때문에 원래 j 인덱스는 key 값으로 변해 고정 값이 된다 (정렬이 완료된 key 값이 됨)
    // 그래서 그거 보다 하나 작은 것까지가 왼쪽 부분집합 이고, 그것 보다 하나 더 큰 인덱스 부터 끝까지가 오른쪽 인덱스가 된다.
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main()
{
    int num = 10;
    int data[10] = {100, 50, 60, 24, 37, 49, 61, 51, 99, 77};

    quickSort(data, 0, num - 1);
    for (int i = 0; i < num; i++)
    {
        cout << data[i] << ' ';
    }
}

/*
    퀵 정렬의 평균 시간 복잡도는 O(n * logN) 이다
    그러나 퀵 정렬의 최악 시간 복잡도는 O(n ^ 2) 이다.
    왜 n ^ 2 되는가?
    pivot 을 무엇으로 잡느냐에 따라 달라진다고 한다.
    대부분은 정렬 방식 중에서 quick sort 를 선호하지만, 
    (c++ 의 STL 에서 정의된 sort 중 기반이 되는 것이 quick sort)
    pivot 에 따라서 안좋은 결과를 낼 수도 있기 때문에 일부 알고리즘 대회에서는 이 quick sort 로 처리했다가
    오류를 낼 수도 있음.
*/

/*
    이미 정렬이 되어있는 데이터의 경우 삽입 정렬이 가장 빠른 정렬 법이지만,
    항상 뭐가 더 좋고 뭐가 더 빠르다 이런 식의 잣대는 의미가 없음
    주어진 데이터 상황에 따라서 올바른 정렬을 선정하는 것이 중요.
*/