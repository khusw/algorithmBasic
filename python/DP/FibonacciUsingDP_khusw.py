'''
    DP 를 이용한 기본 피보나치 수열 계산하기
'''


def dp(x):
    if(x == 1):
        return 1
    if(x == 2):
        return 1
    if(arr[x] != 0):
        return arr[x]
    arr[x] = dp(x - 1) + dp(x - 2)
    return arr[x]


arr = [0] * 100
print(dp(30))
