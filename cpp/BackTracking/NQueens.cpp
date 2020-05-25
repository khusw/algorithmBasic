/*
    N 여왕 문제 (N-Queens Problem)
    이 문제를 풀기에 앞서서 먼저, BackTracking 이란 것에 대해 알아야 한다.
    Backtracking is a technique for listing all possible solutions for a combinatiorial algorithm problem
    백트래킹이란 특정한 어떤 조건을 만족할때만 수행가능한 조합의 수를 전부 살펴보는 것을 말한다.
    일단은 어떤 특정 조건을 만족하는 대상만 쭉 찾는다 그런 의미같다.
    
    N-Queens Problem 을 살펴보면,
    N by N 행렬의 크기를 갖는 체스판에 최대한 많은 Queen 을 두려한다.
    다만, 조건은 서로 공격이 불가능한 위치에 놓으려는게 문제의 목표다.
    체스에서 Queen 은 동서남북, 대각선 으로 이동이 가능하다.
    그러면, N by N 행렬에서 Queen 끼리 서로 공격이 불가능한 위치에 두게하는 모든 경우의 수는 몇개인지 알아내야 하는데,
    가장 쉬운 무식한 방법은 모든 경우의 수를 다 세는 것이다.
    대충 계산하기 위해서 한 column 마다 Queen 을 둔다고 하면은,
    전체 경우의 수는 column 의 수 (N) ^ 한 개의 column 에 Queen 을 놓는 경우의 수(N)
    O(N ^ N) 으로 처리된다. -> 이런 알고리즘은 아무도 안쓰겠지 당연히

    그래서 백트래킹이 등장한 것인데,
    한쪽 column 에 Queen 을 두면 오른쪽 column 으로 이동을 해서 가능한 자리에 Queen 을 둔다
    그리고 또 오른쪽으로 이동해서 Queen 을 두고 이를 끝까지 반복한다.
    두는데, 그냥 순차적으로 다 두는게 아니라,
    promising 검증 이라 해서, 조건 제한을 수행하는 함수를 만들고
    그 함수를 돌면서 수행해야, 나머지 pruned 된 부분집합을 수행하지 않고
    시간복잡도를 줄일 수 있다.
*/

// 아래 코드는 백준 9663번 N-Queen 문제에 대한 해답이다.
#include <iostream>

using namespace std;

int N;          // 문제에서 입력받을 값.
int col[15];    // column 을 말함 최대 15 by 15 정방행렬이라 가정함.
int result = 0; // 최종 가능한 경우의 수의 갯수를 말함.

bool promising(int i) // i 는 행 인덱스
{
    // 백트래킹에 사용될 유효성 검증을 위한 함수
    for (int j = 0; j < i; j++) // j 는 열 인덱스
    {
        // 새 퀸(col[i])과 기존의 퀸(col[j]) 이 같은 행에 있거나, 대각선에 있는 경우
        if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
        {
            return false;
        }
    }
    return true;
}

void N_Queen(int i)
{
    if (i == N) // 들어온 값 i 가 N 인 경우 (마지막 칼럼 번호에 올 경우)
    {
        result += 1;
    }
    else
    {
        for (int j = 0; j < N; j++)
        {
            col[i] = j;       // (i, j) 번째에 j 값을 넣음 (i, j) 에 퀸이 들어갔다는 의미
            if (promising(i)) // 유효성 검증 함수를 추가하여, 유효한 대상이면 아래의 코드를 수행
            {
                N_Queen(i + 1); // 유효성 검증이 된 경우라면, 다음 행으로 넘어가서 수행하도록 재귀 함수 작성 (j 는 열 인덱스, i 는 행 인덱스)
            }
        }
    }
}

int main()
{
    cin >> N;
    N_Queen(0);
    cout << result << '\n';
    return 0;
}