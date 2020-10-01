/*
    Two Pointer Algorithm
    이 알고리즘은 1차원 배열이 입력으로 주어지고,
    각자 다른 원소를 가르키고 있는 2개의 포인터를 조작해서 원하는 것을 얻는 형태의 알고리즘이다.

    N개의 입력이 들어가 있는 1차원 배열이 주어졌을 때, 그 중에서 원소의 합이 M 이 되는 경우의 수를 구하는 문제

    이런 문제는 포인터 두개를 생성하고, start, end
    맨처음에는 둘다 인덱스 0 을 가르키며, 항상 start <= end 라는 조건을 만족시켜야 한다.
    이 두 포인터는 시작 ~ 끝 까지만 갈 수 있다 (배열의 인덱스를 벗어나면 처리 불가)

    start 와 end 의 크기가 서로 동일하다면, 부분 배열의 크기가 0 이라는 뜻이 된다 (아무것도 없는 부분배열)

    반복은 어떻게 하느냐 하면,
    start < N 일 때 까지 계속 반복하고
    반복할때는 아래의 3가지 기능을 수행한다.

    1. 현재 부분합이 M 이상이거나, 이미 end = N 이면 start++ 한다.
    2. 1이 아닌 경우 end++
    3. 현재 부분합이 M 과 동일하면 count++

    이 문제를 풀기 위해서 백준의 2003 번 문제를 풀어본다.
    https://www.acmicpc.net/problem/2003

    2003 번 문제 설명
    N 개로 된 수열 A[N] 이 주어지고, 수열의 i 번째 ~ j 번째 까지의 합이 M 이 되는 경우를 
    모두 카운팅하여 나타내는 프로그램을 작성해라.

    첫번째 입력 줄에는 N 과 M 이 주어지고,
    두번째 입력 줄에는 A[N] 에 들어가게 될 입력 값들이 주어진다.

    예제 입력1
    4 2
    1 1 1 1 
    이면 N = 4, M = 2, A[4] = {1, 1, 1, 1};
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M; // 입력 N, M,
    cin >> N >> M;
    int start, end, count, sum = 0; // two pointer(start, end), count(몇개 있는지 파악), sum(중간합)
    int array[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    while (start < N)
    {                 // 투 포인터 알고리즘의 조건은 start < N 일때 까지 반복
        if (sum >= M) // 부분합이 M 보다 커진 경우 이전의 start 에 해당하는 값을 빼고 start 를 한칸 앞으로 옮김
        {
            sum = sum - array[start++];
        }
        else if (end == N)
        {
            break;
        }
        else
        {
            // 부분합이 M 을 넘지도 않고, end 가 N 이 되지도 않은 경우는 아직 탐색 중이며,
            // 그렇게 하기 위해서 end 를 한칸 앞으로 옮김
            sum = sum + array[end++];
        }

        if (sum == M)
        { // 부분합이 M 과 일치하면 찾는 대상이므로 count++
            count++;
        }
    }

    cout << count;
}