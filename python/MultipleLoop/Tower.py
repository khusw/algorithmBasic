'''
    탑 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/42588

    일직선 상에 놓인 탑이 여러 개 있을 때,
    우측 끝에서 좌측 끝의 탑 방향으로 신호를 보내는데,
    탑 자신보다 크기가 큰 탑만 수신이 가능하고,
    자신 보다 작거나 같은 탑은 수신이 불가 하다.
    그리고 한번 보낸 송신 신호를 다른 탑이 한번 수신하면
    또 다른 탑은 다시 한번 수신이 불가능하다.

    각 탑이 쏜 신호를 수신하는 탑은 몇번째에 위치한 탑인지를 구하는 문제
'''


def solution(heights):
    answer = [0] * len(heights)
    maxHeight = height[0]
    receive = 0
    for i in range(1, len(heights)):
        if maxHeight < height[i]:
            maxHeight = height[i]
            receive = 0
        if height[i - 1] > height[i]:
            receive = i
        answer[i] = receive
    return answer


height = [6, 9, 5, 7, 4]
solution(height)

'''
    항상 가급적이면 O(N^m) 이 되지 않도록 차수를 줄여야한다.
    본래 이문제 처음 풀 때는 이중 포문을 사용해서 O(N^2) 의 형태로 코드를 짰었다.
    일부 케이스에서 통과도 못한다.
    이 문제에서는 입력이 100 이하로 제한 되었기 때문에 몇가지 케이스에서 통과가 가능했다.

    이렇게 이중으로 돌아야할 필요성이 있는 문제는 항상 최소, 최대 변수를 따로 두고,
    그것과 비교를 해서 처리되도록 코드를 바꿔야한다.
'''
