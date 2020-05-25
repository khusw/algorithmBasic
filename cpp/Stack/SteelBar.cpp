/*
    프로그래머스 쇠막대기
    https://programmers.co.kr/learn/courses/30/lessons/42585

    스택을 이용하는 문제 
    이 문제 역시 VPS 와 마찬가지로 굳이 stack 라이브러리를 쓰지 않고
    그냥 카운팅 하는 형식으로 처리가능
    이론적인 기반이 스택이라는 것이지, 
    굳이 스택 라이브러리를 쓰지 않아도 된다는 의미
*/

#include <string>

using namespace std;

int solution(string arrangement)
{
    int answer = 0, cnt = 0, res = 0;
    for (int i = 0; i < arrangement.length(); i++)
    {
        if (arrangement[i] == '(')
        {
            cnt++;
        }
        else
        {
            if (arrangement[i - 1] == '(')
            {
                cnt--;
                res += cnt;
            }
            else
            {
                cnt--;
                res++;
            }
        }
    }
    answer = res;
    return answer;
}

/*
    ( 가 오면 cnt ++
    ) 가 왔을때 바로 전에 ( 였으면 레이저 이므로
    cnt--; res += cnt;
    그게 아니라 단독으로 ) 가 온거면  cnt--, res++

    아래 사이트 설명 참조
    https://kdr0407.tistory.com/37
*/