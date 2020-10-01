/*
    피보나치 수열(Fibonacci sequence)
    이 피보나치 수열을 재귀 함수로 작성을 하면서
    왜 재귀함수가 코드 보기에 직관적이고 심플한지 알아보고,
    또한 왜 재귀함수가 항상 최적의 선택은 아닌지 알아본다.

    피보나치 함수를 수식으로 표현하면 다음과 같다
    F(n) = F(n - 1) + F(n - 2) (n > 1)
    F(n) = n (n <= 1)
    처음에 0, 1 두개만 고정이고 그 다음부터는 이전거 두개의 합으로 구성된다

    두명의 학생이 있다고 가정하자,
    Albert 라는 학생은 피보나치 수열을 구현하기 위해서, 재귀함수가 아닌 반복문을 사용했고,
    Pinto 라는 학생은 피보냐치 수열을 구현하기 위해서, 재귀함수를 사용했다.

    (아래는 pseudo code 로 작성됨)
    - Albert
    int Fib(n) {
        if(n <= 1) return n;
        int F1, F2, F;
        F1 = 0
        F2 = 0
        for (int i = 2; i < n; i++) {
            F = F1 + F2;
            F1 = F2;
            F2 = F;
        }
        return F; 
    }

    - Pinto
    int fib(n) {
        if(n <= 1) return n;
        else return fib(n - 1) + fib(n - 2);
    }

    Albert 학생과 같은 코드를 iterative 방식의 코드라고 부르고
    Pinto 학생과 같은 코드를 Recursive 방식의 코드라고 부름
    
    둘의 근원적인 차이는 무엇이냐면,
    iterative 코드는 F(n) 에 대해서 수행 할 때,
    F(0), F(1), F(2) ... F(n) 이렇게 순차적으로 실행을 하지만,
    Recursive 방식의 코드는 각 경우의 수마다 두개의 함수를 또 호출해야함
    F(5) 를 처리하려면, F(4), F(3) 를 불러야 하고,
    F(4) 를 처리하려면, F(3), F(2) 를 불러야 하고,
    F(3) 를 처리하려면, F(2), F(1) 을 불러야 하며,
    ... F(0) 까지 가는데, 각각 두개로 가지 쳐진것도 F(0) 까지 그 작업을 반복해야함
    즉 F(5) 처리 시에 생겨난 F(4), F(3) 역시도 F(0) 까지 계속 반복해서 끝에 도달해야함

    iterative 방식의 경우 한번씩 처리하고 다음것으로 넘어가지만,
    recursive 방식은 중복된 계산을 또해야 된다는 것임
    그래서 사람이 눈으로 보기에는 재귀함수가 편한 코드이지만,
    컴퓨터가 내부적으로 처리를 할때는 굳이 하지 않아도 될 연산을 계속 반복하기 때문에
    비효율적인 코드가 됨 
    재귀를 쓰기에 효율적인 순간은 아마도 입력 값의 수가 적을 때가 되지 않을까 생각.

    *참고로 Recursion 설명할때 함수 호출에 관한 그림을 이진 트리 형식으로 그렸는데,
    이런 모양의 트리를 recursion tree 라고 부르는듯.
    (재귀함수의 연산은 이 recursion tree 를 봤을때, 연산의 횟수가 지수적으로 증가함을 알 수 있음)

    *추가적으로 memoization 이란 재귀함수가 갖는 문제(반복된 연산 수행)을 개선하기 위한 방법론이다.
    memoization 은 이미 연산한 내용을 데이터에 저장하여 다음 연산에서 이전에 연산했던 내용을 다시 호출할 필요가 있을때
    사용되는 기법이다.
    예를 들면, 피보나치를 n = 5 일때 돌린다고하면,
    fib(1)
    fib(2)
    fib(1) + fib(2)
    fib(2) + (fib(1) + fib(2))
    (fib(1) + fib(2)) + (fib(2) + (fib(1) + fib(2)))
    -> 일반적인 재귀함수의 모습은 이럴 것이다.
    근데 메모이제이션을 사용하면,
    data[1] = fib(1)
    data[2] = fib(2)
    data[3] = fib(3) = data[1] + data[2]
    ...
    메모이제이션을 쓰지 않는 재귀함수에서는 시간복잡도가 O(2^N) 이고,
    메모이제이션을 사용한 경우 시간복잡도는 O(N) 이 된다.
*/

#include <iostream>

using namespace std;

// iterative
int fib(int n)
{
    if (n <= 1)
        return n;
    int F, F1, F2;
    F1 = 0;
    F2 = 1;
    for (int i = 2; i < n; i++)
    {
        F = F1 + F2;
        F1 = F2; // 한칸씩 앞으로 미는 것
        F2 = F;
    }
    return F;
}

// recursive
int Fib(int n)
{
    if (n <= 1)
        return n;
    else
        Fib(n - 1) + Fib(n - 2);
}

// memoization 을 이용한 피보나치 재귀함수
int fibo(int n)
{
    int data[100];
    if (n <= 2)
        return 1;

    if (data[n] != 0) // 원래 C++ 문법에서 이게 되는데 왜 오류 뜨는지 모르겠음.
    // 아마 컴파일러 문제일듯
    {
        return data[n];
    }
    else
    {
        data[n] = fibo(n - 1) + fibo(n - 2);
        return data[n];
    }
}

int main()
{
    int n;
    cin >> n;
    int result = fib(n);
    cout << result << '\n';
}