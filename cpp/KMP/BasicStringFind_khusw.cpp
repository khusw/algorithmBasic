/*
    단순 문자열 탐색 매칭 알고리즘
    (O(N * M) 의 시간 복잡도를 갖는 알고리즘)
*/

#include <iostream>

using namespace std;

int findString(string parent, string pattern)
{
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for (int i = 0; i <= parentSize - patternSize; i++)
    {
        bool finded = true;
        for (int j = 0; j < patternSize; j++)
        {
            if (parent[i + j] != pattern[j])
            { // 하나라도 문자가 일치하지 않는 경우
                finded = false;
                break;
            }
        }
        if (finded)
        {
            // 문자를 찾은 경우
            // 몇번째 인덱스에서 찾았는지 리턴
            return i;
        }
    }
    return -1;
}

int main()
{
    string parent = "Hello World";
    string pattern = "llo W";
    int result = findString(parent, pattern);
    if (result == -1)
    {
        printf("찾을 수 없음");
    }
    else
    {
        printf("%d 에서 찾았다. ", result);
    }
    return 0;
}

/*
    O(N * M) 시간 복잡도를 갖는 알고리즘이어서
    효율적인 것은 아님 
    그래서 문제 풀때, 시간초과 반드시 발생함.
*/