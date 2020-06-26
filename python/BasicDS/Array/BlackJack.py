'''
    블랙잭 문제
    백준 2798 번
    https://www.acmicpc.net/problem/2798

    문제 유형은 배열, 완전 탐색을 사용하는 문제
    추천 풀이 시간 : 20분
'''

'''
    n 은 카드의 총 갯수 이고,
    m 은 합의 최대치 를 의미한다.
    cards 는 카드 번호를 담는 배열이다.
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

'''
    문제 풀이를 위한 핵심 아이디어
    카드 중 3개씩 뽑는 모든 경우의 수느 C(n, 3) 이며, n 은 최대 100. -> 순열과 조합 에서 조합을 의미함
    Combination 의 개념 
    nCr = n(n-1)(n-2)..(n-r) / r!

    여기문제에서 n 개중 카드를 3 개 뽑는다는 것은 nC3 를 의미함

    (이게 모든 컴퓨터에 통용되는 것인지 아니면, 백준 같은 온라인 코테 시스템에서 그런건지는 모르겠으나)
    보통 1초에 1억번 연산을 한다

    n 의 최대가 100 이라고 지정되었기 때문에
    조합의 수가 n(n-1)(n-2) / 3! 으로 표현되므로, n = 100 이어도 대충 한 백만 정도만 나옴
    즉, 1초 내에 연산이 가능한 수준이란 뜻.
    그래서 이런 문제는 3중 포문을 사용해도 된다는 뜻 

    참고로 python 은 1초당 2천만개의 연산을 수행함. (즉 시간 초과 받지 않는 선에서 3중포문 및 브루트 포스 사용 가능)


    이 문제는 index 를 제대로 잡지 못해서 틀린듯
    그리고 합의 배열을 따로 만들 필요가 없는게 파이썬은 자체적으로 max 함수를 제공함
'''
