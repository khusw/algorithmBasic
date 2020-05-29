'''
    제곱근을 이용한 소수 찾기
    Basic.py 에 서술된 것 처럼 
    2 ~ N 까지 모든 수를 전부 탐색해서 소수를 찾으려면,
    O(N) 의 시간복잡도가 소요된다.
    이 시간 복잡도 보다 더 줄이기 위해서 쓰이는 방법 중 하나가 제곱근을 이용하는 것이다.

    어떤 수의 약수는 대칭 관계를 이룬다
    8 = 2 * 4 = 4 * 2 가 그 예다.
    소수판별시에 그 수의 제곱근수 까지만 판별하면 Basic.py 의 방법보다는 조금 더 빠르게 판별이 가능하다.
    루트 8은 2.xxx 이다. 그렇기 때문에 2 까지만 판별하면 이게 소수인지 아닌지 판별할 수 있는 것이다.
    루트를 쓰지 않는 경우 2 ~ 8 까지 전부 비교하게 된다. (비효율적)
'''

import math


def FindPrime(x):
    rootNum = int(math.sqrt(x))
    for i in range(2, rootNum + 1):
        if(x % i == 0):
            return False

    return True


print(FindPrime(29))
