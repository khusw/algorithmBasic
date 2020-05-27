'''
    BOJ 11726번 2*n 타일링
    https://www.acmicpc.net/problem/11726

    DP 를 활용한 Tiling 첫번째 문제 풀기

    n 의 가능 범위는 1 ~ 1000
'''

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
arr = 1001 * [0]


def dp(x):
    if(x == 1):
        return 1
    if(x == 2):
        return 2
    if(arr[x - 1]):
        return arr[x - 1]
    else:
        arr[x - 1] = dp(x - 1) + dp(x - 2)
        return arr[x - 1]


print(dp(n) % 10007)

'''
    파이썬은 다른 언어에 비해 재귀 깊이의 한계치가 작기 때문에
    위 코드 그대로 내보내면 오류가 발생한다
    그래서 
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)

    코드를 추가해준다.

    재귀 함수를 쓸때는 C 계열의 언어가 확실히 더 빠르다.

    똑같은 코드를 C 로 쓸 때는 0ms 나오는데
    python 으로 하니 60ms 나옴
'''
