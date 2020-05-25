/*
    Queue
    FIFO (First In First Out)
    먼저 들어온놈 먼저 나가는것
    기본적인 자료구조

    삽입 7 -> 삽입 5 -> 삽입 4 -> 삭제 -> 삽입 6 -> 삭제

    큐도 PS 에서 직접 구현하지 않음
    그냥 라이브러리 써라.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(7);
    q.push(5);
    q.push(4);
    q.pop();
    q.push(6);
    q.pop();

    while (!q.empty())
    {
        cout << q.front() << '\n';
        q.pop();
    }
}