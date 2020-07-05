/*
    KMP 알고리즘 (Knuth, Morris, Prett Algorithm)

    이중 for 문을 사용한 문자열 탐색 알고리즘의 경우 
    O(N * M) 의 시간복잡도가 소요된다.
    그러나, KMP 알고리즘을 사용하게 되면, O(N + M) 으로 시간 복잡도를 크게 줄일 수 있다.

    1. 접두사(Prefix) 와 접미사(Suffix)
    KMP 를 파악하기 이전에 접두사 접미사에 대한 사전지식이 있어야 한다.
    예를 들면 banana 의 접두사(Prefix) 는 
    b
    ba
    ban
    bana
    banan
    banana
    6개가 된다.
    
    접미사(Suffix) 는 
    a
    na
    ana
    nana
    anana
    banana
    6개가 된다.

    2. pi 배열
    KMP 알고리즘에서 pi 배열이란 
    전체 문자열 중 일부 부분 문자열에서 접두사와 접미사가 같아질수 있는 부분 문자열 중
    가장 긴 것의 길이를 담는 배열이다.

    예를 들면, ABAABAB 의 pi 배열을 구한다 하면,
    i      sub     pi[i]
    0       A       0 (접두사 접미사 같은 부분 없어서 0)
    1      AB       0
    2      ABA      1 (접두사 A 접미사 A 가 같은 부분 1개 존재)
    3     ABAA      1
    4    ABAAB      2 (접두사 AB 접미사 AB 가 같은 부분 2개 존재)
    5   ABAABA      3 (접두사 ABA 와 접미사 ABA 가 같아서 3개)
    6   ABAABAB     2

    그러므로 이 예제에서 pi = [0, 0, 1, 1, 2, 3, 2] 가 된다.  
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makePi(string pattern)
{
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

int main()
{
    string pattern = "abacaaba";
    vector<int> pi = makePi(pattern);
    for (int i = 0; i < pi.size(); i++)
    {
        printf("%d ", pi[i]);
    }
    return 0;
}