'''
    Insertion Sort

    삽입 정렬은 Bubble Sort 나 Selection Sort 처럼 
    모두 자리를 바꾸는 형식이 아니라,

    비교를 하려고 하는 현 위치 인덱스 이하의 인덱스들에 대한 원소들 비교를 수행해서
    자신이 들어갈 위치를 선정해주는 정렬알고리즘

    아래의 코드는 오름 차순 예시임
'''


def InsertionSort(data):
    for i in range(len(data) - 1):
        j = i
        while(j >= 0 and data[j] > data[j + 1]):
            temp = data[j + 1]
            data[j + 1] = data[j]
            data[j] = temp
            j -= 1

    print(data)


listA = [1, 10, 2, 3, 5, 6, 7, 8, 9, 4]
InsertionSort(listA)
