'''
    소수 찾기 코드
    가장 기본적인 내용만을 사용한 파이썬 코드
    (1과 자기 자신의 수 외의 수로 나눠지는 경우 소수가 아님을 활용하여
    입력된 특정한 숫자 하나가 소수인지 아닌지 판별하는 단순한 코드)
'''


def FindPrime(x):
    for i in range(2, x):
        if(x % i == 0):
            return False
    return True


print(FindPrime(67))
