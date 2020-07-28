/*
    LCP (Longest Common Prefix)
    Suffix Array 와 함께 등장하는 알고리즘으로
    Suffix Array 를 구하고 난뒤에 최대 공통 접두사 길이를 갖는 배열을 생성하는 알고리즘임.

    이 알고리즘의 주요 구성요소는 아래와 같다고 볼 수 있음
    (로직이 아니라, 변수를 의미하는 것)
    1. Rank[i]
    : 이 배열은 입력으로 주어지는 문자열 S 에 대한 부분 문자열 S[i:] 가 
    Suffix Array 기법을 이용하여 사전순으로 정렬 했을 때,
    몇번째에 위치해 있는 가를 나타내는 배열이다.

    예를 들면, S = "banana" 일 경우,
    Suffix Array 를 구했을 때,
    SA[6] = {5, 3, 1, 0, 4, 2} 가 되며 
    
    S에 대한 부분 문자열 배열은 (SA 로 인한 정렬 이전의 모습) 
    S[i] = {"banana", "anana", "nana", "ana", "na", "a"} 가 되고,

    SA 로 정렬 된 이후의 S 의 부분 문자열 배열은
    S'[i] = {"a", "ana", "anana", "banana", "na", "nana"} 가 된다.

    이 때, Rank[1] 을 구한다하면,
    SA 를 구한 이후 정렬된 S'[1] 의 SA 상의 인덱스 번호가 무엇이냐를 묻는 것이다.
    Rank[S[1:]] => S[1:] 은 "anana" 로 써 SA 에 의해 현재 인덱스가 2 이다.
    그러므로 Rank[1] = 2 가 된다.

    또한 Rank[] 와 SA[] 는 서로 역함수 관계에 있다.
    Rank[SA[2]] = 2 가 되어,
    SA[2] = 1, Rank[1] = 2 가 되는 관계를 갖고 있다.

    2. LCP(x, y)
    LCP(x, y) 는 문자열 S 에 대한 부분 문자열 
    S[x:], S[y:] 의 최대 공통 접두사 길이가 무엇인지를 나타낸다.
    이 LCP 에 대한 부분은 3가지 공식이 적용된다.

     -1) LCP(SA[y - 1], SA[y]) > LCP(SA[x], SA[z]) (x < y <= z) 가 항상 성립한다
     : 이는 바로 이웃한 두 접미사 (y, y-1) 간의 LCP 가 항상 바로 붙어있지 않고 서로 떨어져 있는 (x, z) 경우 보다는
       LCP 값이 무조건 크다는 의미가 된다.
     
     -2) if LCP(SA[x - 1], SA[x]) > 1, Rank[SA[x - 1] + 1] < Rank[SA[x] + 1]
     바로 이웃한 두 접미사 SA[x - 1], SA[x] 간의 공통 최대 접두사가 1 보다 크다면 (즉 하나라도 같은 접두사가 있다면)
     하나 더 큰 x 가 항상 Rank 값이 크다는 의미가 된다.

     -3) if LCP(SA[x - 1], SA[x]) > 1, LCP((SA[x - 1] + 1), (SA[x] + 1)) == LCP(SA[x - 1], SA[x]) - 1
     이 의미는 서로 이웃한 두 접미사 간의 공통 최대 접두사가 1 보다 크다면 (하나라도 공통인 접두사가 있다면),
     글자를 하나 빼더라도 기존의 LCP 의 값에 1을 빼주면 동일하다는 의미가 된다.
     예를 들면, ana 와 anana 의 경우 앞 글자 a 를 빼서 보면
     na, nana 가 되어 LCP 가 2가되고, 기존의 ana, anana 의 경우 LCP 가 3이 된다.
     그래서 하나를 기존꺼에서 빼주면 동일한 LCP 값을 갖게 된다.

    https://www.crocus.co.kr/614?category=209527
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 600000

using namespace std;

char str[MAX_N]; // 입력 받을 문자열
int t, n, g[MAX_N], tg[MAX_N], RANK[MAX_N], SA[MAX_N], LCP[MAX_N];
/*
    t 는 t = 1, 2, 4, 8, ...
    n 은 str 의 길이,
    g 는 그룹 매핑용 배열
    tg 는 팀그룹 매핑이 아니라, 그룹 매핑할때, 값이 겹칠 수 있기 때문에 임시로 담아 두는 배열임.
    RANK[] 는 SA[] 의 인덱스 번호 매핑
    LCP 는 최대 공통 접두사 길이를 나타내는 배열
*/

bool cmp(int x, int y)
{
    if (g[x] == g[y])
        return g[x + t] < g[y + t];
    return g[x] < g[y];
}

void getSA(const char *str)
{
    t = 1;
    n = (int)strlen(str);

    for (int i = 0; i < n; i++)
    {
        SA[i] = i;
        g[i] = str[i] - 'a';
    }

    // t = 1, 2, 4, 8 ...
    while (t <= n)
    {
        sort(SA, SA + n, cmp);
        tg[SA[0]] = 0; // 임시 배열에 0 부여

        for (int i = 1; i < n; i++)
        {
            // 그룹이 다르면 다음 그룹 으로 매핑시킴
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            else // 그룹이 같으면 같은 번호로 매핑 시킴
                tg[SA[i]] = tg[SA[i - 1]];
        }

        // tg 로 그룹 매핑을 마쳤다면, 진짜 그룹 값을 얻어내야 하므로,
        // tg 의 값을 g 에 넣어줌.
        for (int i = 0; i < n; i++)
        {
            g[i] = tg[i];
        }

        t <<= 1; // t *= 2 와 같음
    }
}

int main()
{
    scanf("%s", &str);
    getSA(str);

    for (int i = 0; i < n; i++)
    {
        RANK[SA[i]] = i;
    }

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        int k = RANK[i];
        if (k)
        {
            int j = SA[k - 1];

            while (str[j + len] == str[i + len])
                len++;
            LCP[k] = len;

            if (len)
                len--;
        }
    }

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

    printf("\n\n[LCP]\n");
    for (int i = 0; i < n; i++)
    {
        if (!i)
            printf("x ");
        else
            printf("%d ", LCP[i]);
    }

    printf("\n\n");

    return 0;
}