/*
    BOJ 1003 피보나치 함수

    단순히 피보나치 수열을 구하는 문제가 아니라,
    피보나치 수열을 재귀 방식으로 호출 했을 때,
    0,1 이 각각 몇번 나타나는지를 파악하는 문제.

    int fibonacci(int n) {
        if (n == 0) {
            printf("0");
            return 0;
        } else if (n == 1) {
            printf("1");
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    만약 fibonacci(3) 라 하면
    fib(3) => fib(2) , fib(1)
    fib(2) => fib(1) , fib(0)
    가 되어,
    fib(1) 은 2번, fib(0) 는 1번 호출 된다.
*/
#include <iostream>

using namespace std;

int mem[41] = {
    0,
    1,
};

int fib(int num)
{
    if (num == 0)
    {
        return mem[0];
    }
    else if (num == 1)
    {
        return mem[1];
    }
    else if (mem[num] > 0)
    {
        return mem[num];
    }
    return mem[num] = fib(num - 1) + fib(num - 2);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    int num;
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        if (num == 0)
            cout << "1 0" << '\n';
        else
            cout << fib(num - 1) << " " << fib(num) << '\n';
    }

    return 0;
}