/*
    스택은 가장 기본적인 자료구조
    LIFO (Last In First Out)
    마지막에 들어온놈 먼저 나감

    삽입 7 -> 삽입 5 -> 삽입 4 -> 삭제 -> 삽입 6 -> 삭제
    7
    57
    457
    57
    657
    57 이 결과물.

    PS 에서 일반적으로는 stack 라이브러리를 사용
    (시간이 없음 직접 구현하려면)
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(4);
    s.pop();
    s.push(6);
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << '\n';
        s.pop();
    }
    return 0;
}
