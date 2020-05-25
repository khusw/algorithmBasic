/*
    단순히 정렬 알고리즘 몇 개 배웠다고 해서, 실전 알고리즘 문제에 적용은 불가능함
    수많은 문제를 풀어야 하고, 그에 따른 노하우를 얻어야함
    그래서 백준, 프로그래머스를 꾸준히 푸는게 중요
    
    BOJ 1181 문자열 정렬
    https://www.acmicpc.net/problem/1181
    이 문제는 알파벳 소문자로 이뤄진 N 개의 단어가 들어올때, 아래 같은 조건으로 정렬하는 프로그램을 작성하는 문제
    1. 길이가 짧은 거 부터
    2. 길이가 같으면 사전 순으로.

    입력이 2만개 이하가 들어오므로 단순한 cpp sort 함수로도 구현 가능

    맨처음 입력은 입력될 문자열의 갯수가 들어오고
    그 다음부터는 문자열이 들어옴
    이 문자열 중 길이 가 짧은거 먼저 sorting 하고 같으면 사전순으로 출력
*/

#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b)
{
    // 길이가 짧은 것을 우선으로 먼저들어온 값이 작으면 1(=true) 리턴
    if (a.length() < b.length())
    {
        return 1;
    }
    else if (a.length() > b.length())
    {
        return 0;
    }
    else
    {
        // 위의 두 경우 모두 속하지 않는다면, 길이가 같은 경우를 의미함.
        // 아래 같은 코드 한줄만 써도 되는 이유는
        // cpp 에서 string 은 비교 연산자가 가능하기 때문이다.
        // string 의 비교연산자에 의해 더 작은것으로 판명되는 것은
        // 사전순으로 앞에 있다는 의미가 된다.
        return a < b;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            // 이 조건문이 들어간 이유는
            // 같은 문자열이 입력될때, 출력하지 말고 패스하라고
            // 조건에 나와있기 때문임.
            continue;
        }
        else
        {
            cout << a[i] << '\n';
        }
    }
}