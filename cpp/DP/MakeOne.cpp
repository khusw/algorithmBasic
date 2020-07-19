/*
    BOJ 1463 1로 만들기
    https://www.acmicpc.net/problem/1463

    어떤 정수 N 이 주어지면 (N 은 1 ~ 백만 까지의 수)
    아래의 세가지 연산만을 사용해서 N 을 1로 만들기 위한 최소 연산의 수를 출력하는 문제

    1. N 이 3으로 나눠 떨어지면, 3으로 나눈다
    2. N 이 2로 나눠 떨어지면, 2로 나눈다
    3. 1을 뺀다.

    * DP 는 재귀로 푸는 방식(Top-Down Approach) 과 반복문으로 푸는 방식 (Bottom-up Approach) 가 있다.
    * 항상 재귀로만 풀지 않아도 되며, 때에 따라서는 반복문으로 표현하는것이 더 나을 수도 있다.
    * 그리고 메모이제이션의 용도와 개념에 대해서 정확히 알 필요가 있다.
    * (이문제에서)메모이제이션을 담당하는 배열은 방문여부를 체크하기 위한 용도 보다도
    * 해당 인덱스의 숫자가 몇번의 최소 연산을 해야하는지를 나타낸다. (방문여부 체크하는 것은 DFS, BFS에서나 하는 것임)
*/

#include <iostream>
#define MAX 1000001
#define MIN(A, B) A > B ? B : A

int D[MAX];
int N;

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    D[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        D[i] = D[i - 1] + 1;
        if (i % 3 == 0)
            D[i] = MIN(D[i], D[i / 3] + 1);
        if (i % 2 == 0)
            D[i] = MIN(D[i], D[i / 2] + 1);
    }

    cout << D[N];

    return 0;
}

/*
    N 은 1 부터 백만까지의 수 범위인데
    1의 경우 연산의 횟수가 0 이기에 D[1] = 0 이며,
    2 이상 부터는 문제에서 언급한 세가지 연산방법을 사용해서 문제를 풀이한다.
*/