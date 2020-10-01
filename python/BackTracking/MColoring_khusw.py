'''
    M Coloring 문제
    어떤 영역이 주어 질 때,
    서로 색깔이 겹치지 않도록 색을 칠하는 알고리즘을 구현하는 문제
    이 문제 역시도 BackTracking 을 활용하면서 유망한 값에 대하여
    색 값을 부여하고 그렇지 않은 부분은 처리하지 않는다.
'''


def m_coloring(i, vcolor):
    if(c_promising(i, vcolor)):
        if(i + 1 == number):
            print(vcolor)
        else:
            for color in range(1, M + 1):
                vcolor[i + 1] = color
                m_coloring(i + 1, vcolor)


def c_promising(i, vcolor):
    switch = True
    j = 0
    while(j < i and switch):
        if(Weight[i][j] and vcolor[i] == vcolor[j]):
            switch = False
        j += 1

    return switch


number = 4  # 총 노드 갯수 n
Weight = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
vcolor = number * [0]  # 컬러 표현을 위한 배열
M = 3  # 색칠할 색의 가짓수 m
m_coloring(-1, vcolor)
