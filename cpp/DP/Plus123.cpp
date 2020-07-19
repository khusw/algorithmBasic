/*
    BOJ 9095 1,2,3 더하기
    https://www.acmicpc.net/problem/9095

    임의의 정수 N 이 주어질 때, 이 정수를 1,2,3 의 합으로 표현하는 방법의 수를 구하는 프로그램

    예를 들면,
    N = 4 일 때,
    - 1+1+1+1
    - 1+1+2
    - 1+2+1
    - 2+1+1
    - 2+2
    - 1+3
    - 3+1
    총 7 가지수가 존재한다.

    입력은 처음줄에 T (테스트 케이스) 가 주어지고 그 다음 줄 부터는 N 이 주어진다.
    출력은 각 N 별 가짓수를 출력하면 된다.
*/

#include <iostream>
#define MAX 11

using namespace std;

int D[MAX];
int T;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    int n;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int j = 4; j <= n; j++)
        {
            D[j] = D[j - 1] + D[j - 2] + D[j - 3];
        }
        cout << D[n] << '\n';
    }

    return 0;
}