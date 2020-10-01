'''
    Backtracking 을 이용한 부분집합의 합을 구하는 문제
    함수 promising 은 백트래킹을 위한 유효성 검증 함수이며, 
    함수 s_s 는 함수 promising 을 이용하여 유망한(promising) 값에 한하여
    부분집합의 합을 수행하는 함수다.
'''


def promising(i, weight, total):
    return (weight + total >= W) and (weight == W or weight + w[i+1] <= W)


def s_s(i, weight, total, include):
    if(promising(i, weight, total)):
        if(weight == W):
            print("sol", include)
        else:
            include[i+1] = 1
            s_s(i + 1, weight + w[i + 1], total - w[i + 1], include)
            include[i+1] = 0
            s_s(i+1, weight, total - w[i+1], include)


n = 4
w = [1, 4, 2, 6]
W = 6

print("items = ", w, "W  =", W)
include = n * [0]
total = 0
for k in w:
    total += k

s_s(-1, 0, total, include)
