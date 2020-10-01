/*
    Rabin Karp Algorithm

    문자열 매칭 알고리즘의 하나로, 특정 상황에서 O(1) 에 해결 가능한 알고리즘 중 하나
    이 알고리즘은 Hash 기법을 사용하고, Hash 는 긴 어떤 데이터를 짧은 데이터로 바꿔주는 기법 중 하나다.
    
    예제)
    abacaaba 의 해시값
    = 97 * 2 ^ 7 +
    98 * 2 ^ 6 +
    ...
    97 * 2 ^ 0
    = 24833

    문자열 각각의 아스키 코드값과 현재 문자가 위치한 인덱스 값을 기반으로 2의 n 승을 곱하는 방식
    일반적으로 해시 함수를 구현할 때, 충돌이 발생하지 않게 끔 계획하는 경우가 대부분이다.
    그래서 이 아스키코드값 기반에 2의 n 승을 곱한 형태는 일반적으로 문자열이 다를 경우, 서로다른 해시값을 갖게 된다.

    abacaabb 의 해시값
    = 97 * 2 ^ 7 +
    98 * 2 ^ 6 +
    ...
    98 * 2 ^ 0
    = 24834

    만약 해시 충돌이 발생하는 경우, 보통은 포인터를 활용해서 연결형 자료구조를 이용해서 해결한다.

    정리하면, 라빈 카프 알고리즘은 여러 개의 문자열을 비교했을 때, 
    먼저 해시 값을 구해서 비교하고, 
    (대부분의 해시 값은 일치해서 충돌하는 일이 거의 없기 때문에) '긴 글' 과 '부분 문자열'의 해시 값이 서로 일치하는 경우에만 
    문자열을 재검사하여 정확히 일치하는지 확인.

    Rabin-Karp Algorithm 의 실전적 예시
    긴 글 : ababacabacaabacaaba
    부분 문자열 : abacaaba

    좌측에서 부터 순차탐색

    - 0번째 인덱스)
    긴 글 : ababacab = 24824
    부분  : abacaaba = 24833

    - 1번째 인덱스)
    긴 글 : babacaba = 24913
    부분  : abacaaba = 24833

    ....

    - 7번째 인덱스)
    긴 글 : abacaaba = 24833
    부분  : abacaaba = 24833

    7번째에서 부분 문자열이 일치함을 알 수 있다.

    라빈 카프 알고리즘 이 처럼 hash 를 사용해서 찾기 때문에
    O(N) 의 시간 복잡도를 갖게됨.
*/

#include <iostream>

using namespace std;

void findString(string parent, string pattern)
{

    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;

    for (int i = 0; i <= parentSize - patternSize; i++)
    {
        // parentSize - patternSize 만큼 순회하는 것은 pattern 덩어리 만큼만 비교하면서 움직이기 때문임.
        // 초기화 작업
        if (i == 0)
        {
            for (int j = 0; j < patternSize; j++)
            {
                // 초기의 hash 값을 설정해서 부여하는 방식
                // 새 해시값 = 기존의 해시값 + 아스키 코드값 * 2의 승수
                // 패턴의 오른쪽 끝에서 부터 2의 승수를 2^n-1 , 2^n-2 ... 2^0 순으로 돌림.
                // 그래서 parent[patternSize - 1 - j] 가 되는 것 (1을 빼는 것은 배열이 0부터 시작하기 때문에, j 는 뒤에서 앞으로 하기 위함)
                parentHash = parentHash + parent[patternSize - 1 - j] * power;
                patternHash = patternHash + pattern[patternSize - 1 - j] * power;
                if (j < patternSize - 1)
                    power = power * 2;
            }
        }
        else
        {
            // 초기 해시 값이 설정된 이후라면 영상 설명에서의 공식대로 2 * (긴글해시값 - 이전문자 해시값) + 새 문자 해시값 을 설정함
            parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
        }
        if (parentHash == patternHash)
        {
            // 서로 일치하는 해시값이 발견 되었을 때.
            bool finded = true;
            for (int j = 0; j < patternSize; j++)
            {
                // 긴글과 부분 문자열간에 문자열 자체도 동일한지 파악
                // 일치하지 않는 문자가 발생하면 그 경우는 해시값만 동일하고, 문자열 자체는 일치하지 않는 것.
                if (parent[i + j] != pattern[j])
                {
                    finded = false;
                    break;
                }
            }
            if (finded)
            {
                printf("%d번째에서 발견.\n", i + 1);
            }
        }
    }
}

int main()
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);
    return 0;
}