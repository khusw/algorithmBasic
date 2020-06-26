'''
    스택의 구조
    나중에 넣은게 먼저 나오는 데이터 구조 (LIFO)

    process 의 함수를 넣는 스택 메모리에 주로 쓰임

    push, pop 이 stack 의 주된 기능
'''

# stack memory 구조 이해를 위한 재귀함수


def recursive(data):
    if data < 0:
        print("ended")
    else:
        print(data)
        recursive(data - 1)
        print("returned", data)


recursive(4)

'''
    stack 의 장단점
    구조가 단순
    데이터 저장 읽기 속도가 빠름

    데이터 최대 갯수를 미리 정해야됨 (python 은 1000번 까지 재귀함수 호출 가능)
    -> 이말은 python 은 이미 내부적으로 1000개 분량의 함수가 들어 갈 수 있는 메모리를 잡아먹고 있다는 뜻임
    -> 즉, 다 쓰지도 않을 함수 메모리를 다 차지 하고 있다는 것.

    저장공간 낭비가 발생할 수 있음 -> 앞에서도 언급 됬듯, 미리 최대 공간을 확보해야 됨

    스택은 통상 함수보다 배열 구조로 구현하는 경우가 많다. (함수로 구현하면 성능상의 문제 발생)
'''

# 아래에는 list 를 이용한 stack 구현

data_stack = list()

data_stack.append(100)
data_stack.append(200)

print(data_stack.pop())

'''
    사실 python 의 list 는 append, pop 만으로도 stack 처럼 구현된다.

    아래의 연습 문제에선 직접 pop, push method 를 구현
'''

stack_list = list()


def push(data):
    stack_list.append(data)


def pop():
    data = stack_list[-1]
    del stack_list[-1]
    return data


for index in range(10):
    push(index)

print(pop())
