'''
    부분 합

    배열의 일부 부분의 합을 계산하는 방법

    이런 문제는 배열이 주어지면
    부분합을 담을 배열을 하나 더 생성하고
    L index, R index 를 활용해서 값을 구하면 된다.
'''

def prefix_sum(data, left, right):
    sumList = []
    summation = 0
    for item in data:
        summation += item
        sumList.append(summation)
    
    print(sumList[right] - sumList[left - 1])

listA = [10, 20, 30, 40, 50]
left = 2
right = 4
prefix_sum(listA, left, right)