/*
    BOJ 9012 번 괄호
    괄호 문자열 (Parenthesis String, PS) 은 두 개의 괄호 기호인 '(' 와 ')' 로 구성된 문자열을 의미한다.
    그 중 괄호의 모양이 올바르게 구성된 문자열을 VPS(Vaild PS) 라 부른다.
    (), ((())), (())() 같은 것들이 VPS 에 해당한다.
    ((), (()(  이런 모양들은 VPS 가 아니다.

    문제는 이런 입력으로 주어진 문자열이 VPS 인지 아닌지 판별해서
    그 결과를 YES, NO 로 나타낼수 있어야 한다.
    T 개의 테스트 데이터 입력이 주어지고, 괄호 문자열의 길이는 2 ~ 50 이하 이다.

    이 문제는 스택을 사용하는 문제이다.
    ( 가 들어오면 넣고, ) 가 들어오면 빼고, 하는 문제.
    그래서 스택 전체가 다 비어있는 상태면 올바른 문자열, 아니면 틀린 문자열.

    stack.top() 할 때, 스택이 아무것도 없는 상태(size = 0) 인 상태에서 이 작업을하면
    out of index 에러가 발생한다.
    값이 없기 때문에 참조가 불가능한듯.
    어쩔수 없이 그러면 갯수 비교를 통한 코드로 바꿀수 밖에 없다.

    그리고 stack 뿐만 아니라 모든 STL 라이브러리에서
    빈 상태에서 참조를 하는 함수 (front(), back() 등) 을 쓰게 되면,
    out of index 에러가 나온다 (아무것도 없기 때문에 참조가 불가능 해서 그런듯)
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;
stack<char> stk;

string VPS(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }

    if (count == 0)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        cout << VPS(str) << '\n';
    }
}