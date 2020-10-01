'''
    블랙잭 문제
    백준 2798 번
    https://www.acmicpc.net/problem/2798
'''

n, m = list(map(int, input().split(' ')))
cards = list(map(int, input().split(' ')))

result = 0
length = len(cards)

for i in range(length):
    for j in range(i + 1, length):
        for k in range(j + 1, length):
            sum_value = cards[i] + cards[j] + cards[k]
            if sum_value <= m:
                result = max(result, sum_value)  # 이런 문제 처럼 합 들 중 최대 구하기 같은 것은
                # result, sum_value 처럼 두개의 변수를 잡고 그 중 큰값을 한변수에 넣는 방식으로 하면
                # 굳이 리스트를 만들지 않고도 구현이됨 (그리고 리스트 메모리 많이 잡아먹음)


print(result)
