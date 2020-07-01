'''
    스킬 트리 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/49993#fn1

    순서를 따라야 하는 스킬트리를 나타낸 변수 skill 이 주어지고,
    유저가 임의로 찍은 스킬트리를 나타내는 변수 skill_tress 가 주어진다.

    skill_trees 변수에서 가이드라인인 skill 변수에 주어진 스킬트리를 제대로 따르는
    문자열이 몇개인지 카운팅하는 문제이다.
'''


def solution(skill, skill_trees):
    answer = 0
    for item in skill_trees:
        temp = ''
        # temp 는 스킬트리에 포함되는 문자만 담기위해서 사용된다.
        isValid = True
        # isValid 는 스킬트리의 순서와 같은지 파악한다.

        for s in item:  # 유저가 찍은 스킬트리 (item) 에서 문자 하나씩 s 라는 변수로 떼와서
            # 정해진 스킬트리 skill 변수에 포함되어 있는지 파악
            if skill.find(s) != -1:  # 없으면 -1 임
                temp += s  # -1 이 아닌 경우이므로 존재함, 그래서 temp 에 넣음

        for index in range(len(temp)):
            if skill[index] != temp[index]:
                isValid = False  # 스킬트리의 순서와 맞지 않는 경우
                break

        if isValid == True:  # 스킬트리의 순서에 일치한 경우
            answer += 1
    return answer
