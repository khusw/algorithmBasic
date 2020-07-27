/*
    접미사 배열(Suffix Array)

    어떤 문자열이 주어지면, 이 문자열의 접미사만 배열에 담아서
    사전순으로 재 나열하여 처리하는 방식
    접미사 배열은 문자열 처리 문제 LCP(Longest Common Prefix) 개념과 함께 자주 등장.

    접미사 배열을 단순히 사전순으로 재 정렬하는 방식은 
    아주 단순한 방법을 쓸 때는 O(N^2logN) 이 소요됨.
    그러나 멘버-마이어스 알고리즘 이란 것을 사용하면,
    O(nlog^2n) 에 동작하는 접미사 배열을 구할 수 있음.

    예를 들면, banana 가 입력으로 주어질 때,
    이를 멘버-마이어스 알고리즘으로 정렬을 하면

    d = 1 일 때 (앞의 한 글자만으로 정렬을 시도하는 경우)
    anana
    ana
    a
    ------> 첫 한 글자 'a' 를 기준으로 구분한 접미사
    banana
    ------> 첫 한 글자 'b' 를 기준으로 구분한 접미사
    nana
    na
    -----> 첫 한 글자 'n' 을 기준으로 구분한 접미사.

    d = 2 일 때 (앞의 두 글자 만으로 정렬을 시도하는 경우)
    a
    ------> 첫 두 글자 'a ' 기준
    ana
    anana
    ------> 첫 두 글자 'an' 기준
    banana
    ------> 첫 두 글자 'ba' 기준
    nana
    na 
    ------> 첫 두 글자 'na' 기준

    그 다음은 d = 4, d = 8 .... 인데
    banana 는 총 6글자 이므로, d = 4 까지만 수행

    이런식으로 d 를 2배씩 늘려서 정렬을 시도하는 것이 
    멘버-마이어스 알고리즘.

    이런식으로 정렬을 하는 것은 
    2배씩 경우의 수를 나눠서 정렬 하는 것 이므로,
    O(logN) 의 시간복잡도를 소요하는 것이고,
    총 n 개의 글자 (banana 에선 n = 6) 를 가지고, 정렬하므로 O(nlogn)
    한번 정렬 시도시 O(logn) * 전체 정렬 시도시 O(nlogn) 
    그러므로 총 정렬 시간은 O(nlog^2n) 이 소요된다.
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 600000

using namespace std;

char str[MAX_N]; // 문자열이 들어가는 배열
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N];
// t 는 단어의 위치, n 은 str 길이, g 는 그룹, tg 는 팀 그룹, SA 는 Suffix Array

bool cmp(int x, int y)
{
    // 그룹 번호를 비교하는 함수
    if (g[x] == g[y])
    {
        return g[x + t] < g[y + t];
    }

    // 그룹 번호가 다를 때.
    return g[x] < g[y];
}

void getSA(const char *str)
{
    t = 1;
    n = (int)strlen(str);

    for (int i = 0; i < n; i++)
    {
        // 첫 글자에 의한 그룹을 정해주는 전처리 과정
        // d = 1 일 때, 그룹 배열과 SA 를 초기화해주는 작업임.
        // SA 는 인덱스 번호만을 값으로 담고 있고, G 는 아스키 코드값 뺄셈연산을 통해서 나온 값을 기준으로 그룹을 나눈 배열임.
        SA[i] = i;
        g[i] = str[i] - 'a';
    }

    // 1, 2, 4, 8 .. 순으로 정렬
    while (t <= n)
    {
        g[n] = -1;             // 배열은 0 부터 시작해서 n 번째에는 글자의 길이에 해당하는 위치이면서 끝 위치여서 -1 을 넣음
        sort(SA, SA + n, cmp); // 그룹 기준 정렬
        tg[SA[0]] = 0;         // 다음 그룹 할당을 위한 temp group 의 첫번째 번호 배정

        // 다음 그룹 배정
        for (int i = 1; i < n; i++)
        {
            // 그룹이 다른 경우, 다음 그룹 번호 할당
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            // 그룹 같을 때 같은 그룹 번호 배정
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }

        // 새 그룹 할당
        for (int i = 0; i < n; i++)
        {
            g[i] = tg[i];
        }

        t <<= 1; // bitwise assignment operator
    }
}

int main()
{
    scanf("%s", &str);
    getSA(str);

    printf("\n[Suffix Array]\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str + SA[i]);
    }

    printf("\n[Suffix Array Order]\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", SA[i] + 1);
    }

    printf("\n\n");

    return 0;
}