/*
    1 ~ N 까지 전부 비교해서 소수인지 판별하지말고
    판별할 수의 제곱근 만큼만 비교를 하면
    O(N) 의 시간복잡도를 O(N^(1/2)) 로 줄일 수 있다.

    이 파일은 제곱근을 이용한 소수 판별을 나타낸 파일이다.
*/

#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x)
{
    int end = (int)sqrt(x);
    for (int i = 2; i <= end; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    printf("%d", isPrimeNumber(67));
    return 0;
}