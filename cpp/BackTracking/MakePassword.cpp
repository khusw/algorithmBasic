/*
    BOJ 1759 암호 만들기
    https://www.acmicpc.net/problem/1759

    문제에서 암호가 서로 다른 L 개의 알파벳 소문자로 구성되어 있으며,
    최소 한 개의 모음(a, e, i, o, u) 과 최소 두 개의 자음으로 구성되어 있다.
    또한 암호는 정렬된 문자로 되어 있다 (abc 는 되지만, bac 는 안됨)

    또한 C 개의 문자가 주어지는데, 암호의 가능성이 있는 문자로 주어지는 문자들이다.

    즉 총 문자의 갯수는 C 개 이며, 그 중에서 
    제한 조건에 따라서 L 개의 문자를 선택하는 그런 문제이다.

    즉, 조합 공식 cCl 이라 볼 수 있다.

    제한 조건은
    1. 모음이 한개 이상이어야 한다. 
    2. 자음이 두개 이상이어야 한다. - 모음이 하나이상 있는지만 확인하면 2번은 확인할 필요 없음
    3. 글자의 최소 갯수가 3개 이상이다. - 이미 문제에서 L,C 가 3 이상으로 입력이 들어오는 조건이 설정되어 있음
    4. 오름차순으로 암호가 정렬되어야 한다. - sort() 로 정렬
    5. C 개의 문자에서 위의 모든 조건을 만족하는 L 개의 문자가 주어지면 탐색을 종료하고 백트래킹을 이용해서 전으로 돌아가야 한다.

    결국 1, 5만 잘 처리하면 문제를 풀 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MOEUM 5
#define MAX 16

using namespace std;

char arr[MAX];
set<char> moeum({'a', 'e', 'i', 'o', 'u'});
vector<char> dfs_vec;
int L, C;

void dfs(int depth, int moeum_num, int jaeum_num, int start)
{
    if (depth == L - 1)
    {
        if (moeum_num < 1 || jaeum_num < 2)
        {
            return;
        }

        for (int i = 0; i < L; i++)
        {
            cout << dfs_vec[i];
        }
        cout << '\n';
        return;
    }

    if (start >= C)
    {
        return;
    }

    if (L - (moeum_num + jaeum_num) > C - start)
    {
        return;
    }

    for (int i = start; i < C; i++)
    {
        dfs_vec.push_back(arr[i]);

        if (moeum.find(arr[i]) == moeum.end())
        {
            // moeum.end() 와 같다는 뜻은 모음을 찾지 못했다는 뜻임
            // 즉, 자음만 있다는 뜻.
            dfs(depth + 1, moeum_num, jaeum_num + 1, i + 1);
        }
        else
        {
            // 모음을 발견한 경우
            dfs(depth + 1, moeum_num + 1, jaeum_num, i + 1);
        }

        dfs_vec.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + C);

    for (int i = 0; i < C; i++)
    {
        dfs_vec.push_back(arr[i]);

        if (moeum.find(arr[i]) == moeum.end())
        {
            // 자음인 경우
            dfs(0, 0, 1, i + 1);
        }
        else
        {
            dfs(0, 1, 0, i + 1);
        }

        dfs_vec.pop_back();
    }
}