# 백준 2920 음계
# https://www.acmicpc.net/problem/2920
# 추천 풀이 시간 15 분
scale = [int(x) for x in input().strip().split()]

cnt = 0

for i in range(len(scale) - 1):
    if scale[i] < scale[i + 1]:
        cnt += 1
    else:
        cnt -= 1

if cnt == 7:
    print("ascending")
elif cnt == -7:
    print("descending")
else:
    print("mixed")


'''
    강의 답안
    
    문제 풀이의 핵심 아이디어는 
    1. 리스트의 원소를 차례대로 비교한다
    2. 비교할 때 두 원소를 기준으로 오름차순/내림차순 여부를 체크한다.

    오름차순, 내림차순 각각에 Boolean 값을 부여해서
    두 원소를 비교해서 기준에 맞지 않는 경우 False 로 부여해줌

    둘다 False 면 Mixed 로 처리함
    하나만 True 면 그 경우를 출력

    참고로 한줄로 입력을 쭉 받을 때 python 은
    a = list(map(int, input().split(' '))) 으로 처리하면
    1 2 3  이런 식으로 들어오는 데이터를 [1,2,3] 으로 처리 가능
    -> 어떻게 이렇게 처리가 가능한가?
    list(map(함수, 리스트or튜플)) 형태로 정의하는 함수는
    리스트or튜플에 들어간 값을 정의한 함수 형태로 바꿔서
    리스트로 변환해라 라는 뜻이 된다.

    list(map(int, [1.2, 2.3, 3.6])); 을 시행하면
    [1,2,3] 으로 int 형으로 바뀌게 된다.

    즉, a = list(map(int, input().split(' '))) 의 결과는
    [1, 2,.....] 이 되는 것
    
'''

scales = list(map(int, input().split(' ')))

ascending = True
descending = True

for i in range(len(scales) - 1):
    if scales[i] < scales[i + 1]:
        descending = False
    elif scales[i] > scales[i + 1]:
        ascending = False

if ascending:
    print("ascending")
elif descending:
    print("descending")
else:
    print("mixed")


'''
    참고로 백준에 코드를 제출할 때
    Python 3 로 제출하는 거랑,
    PyPy 3 로 제출하는 거랑 성능적인 부분에서 약간 다름

    전자는 메모리를 후자보다는 덜 잡아먹지만,
    후자는 전자보다 메모리를 많이 잡아먹음

    PyPy 3 가 메모리를 더 잡아먹고, 시간도 좀 더 오래걸린다.
'''
