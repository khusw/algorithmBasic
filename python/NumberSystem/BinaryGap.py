'''
    Bianry Gap

    임의의 양의 정수가 주어지고,
    이 양의 정수를 이진수로 전환한 뒤에
    이진수 값 1을 양끝으로 갖는 부분집합에서 0의 갯수를 출력하는 문제

    예를 들면,
    십진수 32 는 이진수로 전환시 100000 가 되는데 양끝에 1 이 없으므로, 이때의 binary gap 은 0 이다.
    십진수 529 는 이진수로 전환시 1000010001 가 되는데 양끝에 1 이되는 구간이 두 구간이 있고 이때의 binary gap 은 4, 3 이다 
    십진수 20 은 이진수로 전환시 10100 가 되는데 양끝에 1 이 되는 구간이 한 구간만 존재하며 이때의 bianry gap 은 1 이다.
    십진수 15 는 이진수로 전환시 1111 가 되는데 양끝에 1 이 되는 구간이 있으나, 0이 하나도 없으므로, binary gap 은 0 이다.

    이런식으로 bianry gap 을 구해서 binary gap 중 가장 큰 값을 리턴하는 함수를 만들어야 한다.
'''
def make_binary(data):
    remainder = 0
    quotient = data
    while(quotient > 1):
        quotient = data / 2
        remainder = int(data % 2)
        data = quotient
        binaryList.append(remainder)
    binaryList.reverse()
    
def two_pointer():
    length = len(binaryList)
    cnt = 0 # counting binary gap 
    start = 0
    end = 1
    check = False # check whether '1' existed or not.
    
    while(start < length and end < length):
        if binaryList[end] == 0:
            end += 1
            cnt += 1
        else:
            start = end
            end += 1
            check = True
            binaryGapList.append(cnt)
            cnt = 0 
    
    if check:
        binaryGapList.sort()
        return binaryGapList[-1]
    else:
        return 0

def solution(N):
    make_binary(N)
    answer = two_pointer()
    return answer

binaryList = [] 
binaryGapList = [] 