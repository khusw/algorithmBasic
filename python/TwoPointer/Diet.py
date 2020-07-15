'''
    백준 1484 다이어트 (BOJ 1484)
    https://www.acmicpc.net/problem/1484

    투포인터 개념을 활용하여, 가능한 몸무게를 출력하는 문제이다.

    문제에서는 G 몸무게란게 있다.
    G 몸무게는 현재의 몸무게의 제곱에 성원이 기억하고 있는 몸무게의 제곱을 뺀 값으로 결정된다.

    입력은 G 값만 주어지고 G 값은 십만 이하의 자연수다.
    출력은 성원의 현재 몸무게를 오름차순으로 출력한다 (가능한 현재 몸무게가 없는 경우 -1 로 처리한다.)

    제곱수를 이용해서 투포인터를 활용해서 순회한다.

    1. start, end 인덱스를 생성한다
    2. arr[end] - arr[start] 가 G 보다 작으면 end 를 하나 증가시킨다.
    3. arr[end] - arr[start] 가 G 보다 크면 start 를 하나 증가시킨다.
    4. arr[end] - arr[start] 가 G 와 동일하면 배열에 end 값을 추가한다.
    5. 이 과정을 start 와 end 가 배열의 끝까지 도달하여 더이상 나가지 못할 때 까지 진행한다.

'''


def search():
    start = 0
    end = 0
    check = False
    while(start <= end and end < n):
        W = weightList[end] - weightList[start]
        if(W < G):
            end += 1
        elif (W == G):
            check = True
            print(end)
            end += 1
        else:
            start += 1

    if(not(check)):
        print(-1)


n = 317  # 루트 십만 은 약 316.xx 이다.
weightList = [i * i for i in range(n)]  # 가능한 몸무게를 담는 리스트
G = int(input())
search()
