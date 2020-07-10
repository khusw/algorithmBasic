'''
    투 포인터 기법

    어떤 배열이 주어지고, 그 배열에서 특정합이 몇개있는지 파악하는 문제
    예를 들면, arr = [1,2,3,2,5] 가 배열로 주어질때 부분배열의 합이 5가 되는 경우는 몇개?

    총 3개가 존재한다.
    arr[1] + arr[2]
    arr[2] + arr[3]
    arr[4]

    보통은 이중 포문을 사용해서 탐색을 하는 것을 생각하는데
    투 포인터 기법을 사용하면, O(N^2) 의 시간 복잡도를 요구하지 않고,
    O(N) 선에서 처리가 가능하다

    투포인터를 사용하려면

    1. start, end 포인터 두개를 생성한다, 두 포인터는 배열의 첫 인덱스에서 시작
    2. 부분합이 M 과 같으면 카운팅을 한다
    3. 현 부분합이 M 보다 작거나 같으면 end 를 1 증가
    4. 현 부분합이 M 보다 크면 start 를 1 증가
    5. 모두 돌릴 때 까지 2 ~ 4 반복
'''


def TwoPointer(data):
    M = 5
    end = 0
    count = 0
    summation = 0
    for start in range(len(data)):
        while summation < M and end < M:
            summation += data[end]
            end += 1
        if summation == M:
            count += 1
        # data[start] 를 빼주는 이유는, start 가 1 증가할때, 그에 따른 부분합도 달라지기 때문이다.
        summation -= data[start]

    print("M 의 갯수 : ", count)


listA = [1, 2, 3, 2, 5]
TwoPointer(listA)
