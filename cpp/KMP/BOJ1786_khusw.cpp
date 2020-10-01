/*
    찾기 (백준 1786 번)
    https://www.acmicpc.net/problem/1786

    두개의 문자열이 주어진다.
    T 는 text,
    P 는 pattern 을 의미한다.

    Text 내부의 부분집합으로써, Pattern 이 나타나야 하므로
    Text 의 길이를 N, Pattern 의 길이를 M 이라하면,
    N >= M 으로 볼 수 있다.

    이 문제는 두 입력 T 와 P 에 대해서 
    P 가 T 의 몇번째에 나타나는가를 판별하는 문제이다.
    일반적인 문자열 패턴 검출(simpleFind.cpp 파일 참조) 방법으로는 문제를 풀 수 없고 
    (시간 초과 오류, 단순 문자열 패턴 검출법을 쓰면 O(N * M) 의 시간 복잡도를 갖게 됨.)

    여기서는 KMP 방식으로 문제를 풀어야 한다 (문제에서 요구하는 내용)

*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int pCount;
vector<int> pPos;

vector<int> makePi(string pattern)
{
    int patternSize = pattern.size();
    vector<int> pi(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[j] != pattern[i])
        {
            j = pi[j - 1];
        }
        if (pattern[j] == pattern[i])
        {
            pi[i] = ++j;
        }
    }
    return pi;
}

void KMP(string parent, string pattern)
{
    vector<int> pi = makePi(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                // 전체를 다 순회 했을 때.
                pPos.push_back(i - patternSize + 2); // 몇번째의 위치에 패턴이 나타나는지 담는 배열
                j = pi[j];
                pCount++; // 몇번 등장하는 지 카운팅
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);
    KMP(parent, pattern);

    printf("%d\n", pCount);
    for (int i = 0; i < pPos.size(); i++)
    {
        printf("%d ", pPos[i]);
    }
    return 0;
}