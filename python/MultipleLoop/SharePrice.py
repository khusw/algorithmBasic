'''
    주식가격 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/42584

    초 단위로 기록된 주식 가격이 담긴 배열 prices 가 주어지고
    각 초당 가격이 떨어지지 않은 기간이 몇초인지 계산하는 문제

    문제 분류 상에는 스택/큐 라 되어 있는데, 스택 큐가 무슨 상관이 있는지는 잘 모르겠다.
'''


def solution(prices):
    answer = [0] * prices
    for i in range(len(prices)):
        for j in range(i+1, len(prices)):
            answer[i] += 1
            if prices[i] > prices[j]:
                break
    return answer


'''
    처음에 문제 풀 때, 이중 포문을 쓰긴 했으나,
    O(N^2) 이 되기 때문에, 시간 초과가 나서
    투포인터를 써야 되는거 아닌가 생각했다.
    근데 나중에 보니, append 해서 넣는 거랑
    위 코드 처럼 해당 인덱스 번호에 +1 하는 거랑 연산 속도가 다른것 같다
    그래서 위의 이중 포문은 시간초과가 안나고 
    변수 새로 만들어서 append() 할 때는 시간 초과가 난다

    근데 다른 사람들 코드 보면 
    append 해도 통과가 되는 사람이 있긴 하던데
    그냥 코드 실력 차이인건가 싶다..
'''
