'''
    선택 정렬 (Selection Sort)
    선택 정렬은 가장 작은 혹은 가장 큰 값을 선정해서 오름차순 또는 내림차순을 하는 알고리즘
    선택정렬은 일반적으로 O(N^2) 의 시간 복잡도를 가짐

    아래의 예제는 오름 차순을 하는 예제로 가장 작은 값을 맨 앞으로 보낸다는게 핵심.
'''


def SelectionSort(data):
    length = len(data)
    for i in range(length):
        minimum = 9999
        for j in range(i, length):
            if data[j] < minimum:
                minimum = data[j]
                index = j
        temp = data[i]
        data[i] = data[index]
        data[index] = temp

    for item in data:
        print(item, end=' ')


listA = [1, 10, 8, 7, 6, 3, 4, 2, 5, 9]
SelectionSort(listA)
