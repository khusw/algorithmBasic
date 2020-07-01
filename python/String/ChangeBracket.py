'''
    괄호 변환 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/60058

    괄호로 된 문자열이 주어지면 문제의 설명 대로,
    괄호를 바꾸는 문제이다.

    입력으로 들어오는 문자열은 전부 '(', ')' 으로만 구성되어 있으며,
    둘의 갯수가 동등할 경우, '균형 잡힌 괄호 문자열'
    갯수도 동등하며, 짝도 맞는 경우, '올바른 괄호 문자열' 이라 부른다.

    level 2 문제가 맞는지 모르겠지만,
    일단 아직 초보자라 그런지 꽤나 어렵게 느껴졌다.
'''

# 문자열이 '균형 잡힌 괄호 문자열' 인지 판별하는 함수


def checker(text):
    left = 0  # '(' 문자열 몇개인지 카운팅
    right = 0  # ')' 문자열 몇개인지 카운팅
    for item in text:
        if item == '(':
            left += 1
        else:
            right += 1
        if left < right:
            return False

    return True

# 문자열 w 를 u 와 v 로 나누기 위한 함수


def divisor(w):
    if w == '':  # 빈 문자면 그대로 빈 문자열 리턴
        return ''
    left = 0
    right = 0
    last = ''  # 마지막 문자

    for index in range(len(w)):
        if w[index] == '(':
            left += 1
        else:
            right += 1
        last = w[index]
        if left == right:  # 갯수가 같으므로 '균형 잡힌 괄호 문자열'
            if last == ')':  # 균형 잡힌 문자열 이면서, 닫는 괄호로 끝났으므로, 올바른 문자열
                # 여기까지 올때의 index 까지는 올바른 문자열이란 소리고,
                # python 에서 문자열 slicing 할 때는 index + 1 해야 제대로 나옴
                # w[ : index + 1 ] 부분은 u 를 의미하며 (u 는 가장 먼저 균형잡힌 문자열을 만들어주는 구간)
                # w[index + 1 : ] 부분은 v 를 의미한다 (w 를 u, v 로 나눌 때 먼저 나눠진 u 에 의해 남은 문자열이 v)
                # v 에 divisor 를 붙인 이유는 문제 설명에서 v 부분은 재귀적으로 재실행 한다고 설명되어 있다.
                return w[:index+1] + divisor(w[index+1:])
            else:
                return reverse(w[:index + 1], divisor(w[index + 1:]))


def reverse(u, v):  # 문제 설명의 4 번 이하 과정을 표현한 함수
    empty = '('  # 처음 빈 문자열에 ( 를 붙인다.
    # v 에 대해 재귀적으로 수행한 결과 (divisor에 의한 결과물이 여기선 v) 인 v 를 붙이고 그 뒤에 ')' 를 붙인다.
    empty += v + ')'
    # 첫번째 문자(0 index) 와 마지막 문자(len(u) - 1 index 부분) 를 제외하기 위해 for 범위가 이와 같이 잡힘
    for index in range(1, len(u) - 1):
        if u[index] == '(':  # 뒤집기 위한 용도
            empty += ')'
        else:
            empty += '('
    return empty  # 앞의 모든 과정을 다 거치고 생성된 문자열을 반환


def solution(p):
    if checker(p):  # 올바른 괄호 문자열이면 별도의 작업 필요 없이 바로 리턴
        return p

    return divisor(p)  # 그외의 경우라면 문자를 u,v 로 나눠서 정의된 함수들을 수행.
