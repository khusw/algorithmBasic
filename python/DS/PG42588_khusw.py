'''
    탑 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/42588
'''


def solution(heights):
    answer = [0] * len(heights)
    maxHeight = height[0]
    receive = 0
    for i in range(1, len(heights)):
        if maxHeight < height[i]:  # 항상 최대높이는 결과값이 0으로 된다.
            maxHeight = height[i]
            receive = 0
        # 여기서 큰 값이란, 높이가 큰 탑이고, 높이가 큰 탑의 index + 1 을 결과로 넣어야 올바르게 나온다.
        if height[i - 1] > height[i]:
            receive = i  # 그래서 receive 가 i - 1 이 아닌 i 가 된다.
        # 한번 receive 값을 지정하고 또 다른 큰 대상(두 if 조건을 통과하지 않는)이 나타나서 receive 값이 바뀌지 않는 이상 그대로 유지됨.
        answer[i] = receive
        # 문제의 첫번째 예시 [6,9,5,7,4] 에서 5, 7 은 9만 수신함 그래서 결과 값이 둘다 2 로 통일됨.
    return answer


height = [6, 9, 5, 7, 4]
solution(height)
