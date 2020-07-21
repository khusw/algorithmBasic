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
#define MAX 41

using namespace std;

int vec[MAX];
int vec_zero[MAX];
int vec_one[MAX];
int fib[MAX];
int zero_cnt;
int one_cnt;

void sequence(int num)
{
    if (num == 0)
    {
        fib[0] = 1;
        zero_cnt = fib[num];
        return;
    }
    if (num > 0)
    {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= num; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    zero_cnt = fib[num - 1];
    one_cnt = fib[num];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> vec[i];
    }

    for (int i = 0; i < T; i++)
    {
        sequence(vec[i]);
        vec_zero[i] = zero_cnt;
        vec_one[i] = one_cnt;
        zero_cnt = 0;
        one_cnt = 0;
    }

    for (int i = 0; i < T; i++)
    {
        cout << vec_zero[i] << " " << vec_one[i] << '\n';
    }

    return 0;
}