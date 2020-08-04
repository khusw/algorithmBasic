/*
    BOJ 6603 로또
    https://www.acmicpc.net/problem/6603

    독일의 로또는 1 ~ 49 까지의 수 중 6개를 선택해서 당첨되며,
    
    로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49 가지수 중에서 k (k > 6) 개의 수를 골라
    집합 S 를 생성하고 그 숫자들만 가지고 번호를 선정하는 것이다.
    예를 들면, k = 8 일때 S = {1,2,3,5,8,13,21,34} 같이 골랐다면, 집합 S 에서
    고를 수 있는 모든 경우의 수는 28 가지가 된다 (S 에서 6개만 추출)
    {1,2,3,5,8,13}, {1,2,3,5,8,21}, {1,2,3,5,8,34} ....

    입력은 첫글자에 k 가 주어지고 k 다음 한칸씩 띄어쓰기로 S 에 포함되는 숫자가 주어진다
    입력은 0이 들어올때까지 계속 받게된다.

    출력은 각 테스트 케이스 별로, 가능한 모든 경우의 수를 출력함 
    (총 갯수가 아니라 가능한 모든 테스트 케이스를 리턴)

    이문제의 탐색 방식은 DFS, 검증 알고리즘은 배열의 원소 갯수가 6개가 됬을때, 백트래킹을 시도하는 것이다.
*/

#include <iostream>
#define MAX 13

using namespace std;

int s[MAX]; // 집합 s
int combi[MAX];
int k = -1; // 입력 k

void dfs(int start, int depth)
{
    if (depth == 6) // 백트래킹의 제한조건에 해당하는 부분
    {
        for (int i = 0; i < 6; i++)
        {
            cout << combi[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < k; i++)
    {
        // 재귀함수가 끝나고 돌아오면 s 의 다음 인덱스로 넘어가서 부여하기 때문에
        // 이것은 백트래킹 방법을 그래도 적용한 형태임
        combi[depth] = s[i];
        dfs(i + 1, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> k && k)
    {
        for (int i = 0; i < k; i++)
        {
            cin >> s[i];
        }

        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}