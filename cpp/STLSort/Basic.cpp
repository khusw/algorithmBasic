/*
    STL 의 Sort 에 대해서 알아본다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a + 10);
    /*
        배열 자체가 주소를 의미한다
        그래서 a 라고만 쓰면 a[0] 을, a + 10 은 a[9] 를 의미.
    */
    for (int i; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
}
/*
    STL sort 의 장점은 정렬 기준을 프로그래머 마음대로 지정이 가능하다.
    sort(a, a + n); 하면 그냥 오름 차순 정렬이지만,
    sort(a, a + n, func); 이라 쓰면, 함수 func 에 정의된 정렬 기준에 따라
    a 가 정렬된다.

    bool compare(int a, int b) {
        return a < b;
    }
    라고 함수를 정의하면, a < b 일 때 즉, 오름 차순으로 정렬해라 라는 뜻이 된다.
*/