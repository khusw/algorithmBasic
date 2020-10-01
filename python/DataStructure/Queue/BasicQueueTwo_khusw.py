'''
    FIFO 가 아닌 다른 큐
'''

# LIFO (Last In First Out) Queue

import queue

data_queue = queue.LifoQueue()  # LIFO 큐 클래스를 이용해 인스턴스 생성

data_queue.put("good")
data_queue.put(1)

print(data_queue.qsize())

print("LIFO Queue 1 : ", data_queue.get())  # 마지막에 넣은 1이 먼저 출력된다.

# 사실상 스택..

# 우선순위 큐 Priority Queue
# 데이터를 넣을 때 우선순위 번호도 같이 넣는 방법

data_queue2 = queue.PriorityQueue()

'''
    python 에서 우선순위 큐를 사용할 때,
    데이터를 넣을 경우 
    tuple 형태로 데이터를 넣어야하며
    (우선순위, 데이터값) 으로 넣어줘야 한다.
'''
data_queue2.put((2, "good"))  # 우선순위가 2 인 데이터 "good"
data_queue2.put((9, 1000))
data_queue2.put((1, 900))

# 참고로 우선순위 번호가 낮을 수록 더 우선순위가 높은 것
# 위에 데이터는 첫번째로 하느냐, 9번째로 하느냐, 2번째로 하느냐 를 말함

print("PQ 1 : ", data_queue2.get())

# OS 에서의 멀티 태스킹을 위한 프로세스 스케쥴링 기법을 구현할 때 Queue 가 자주 쓰인다.


# 연습 예제
# list 로 queue 를 직접 구현

li = [1, 2, 3, 4]


def enq(data):
    li.append(data)


def deq():
    data = li[0]
    del li[0]
    return data
