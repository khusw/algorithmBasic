'''
    Bubble Sort 

    Selection Sort 는 제일 작은/큰 값을 선정해서 위치를 바꿨다면
    Bubble Sort 는 양옆에 끼리 비교 해서 옆으로 넘기는 방식

    아래 코드는 오름 차순 기준
'''


def BubbleSort(data):
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            if data[i] > data[j]:
                temp = data[i]
                data[i] = data[j]
                data[j] = temp

    for i in range(len(data)):
        print(data[i], end=' ')


listA = [1, 10, 8, 7, 6, 5, 4, 2, 3, 9]
BubbleSort(listA)
