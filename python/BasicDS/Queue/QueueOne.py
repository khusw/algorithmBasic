'''
    Queue 는 OS, Network 등 다방면에서 사용

    Queue 의 특성과 용어, 대표적 알고리즘 등 이해하기

    Queue 는 FIFO (First In First Out) 먼저 들어간놈 먼저 나온다.

    Queue 는 index 로 접근하는게 아니라 그냥 Enqueue, Dequeue 로 만 접근 한다.
    순서대로 꺼내는것, 넣는 것 말고 없음

    큐는 우선순위큐, 원형큐, LILO 큐 등 다양하게 있다.
'''

import queue

data_queue = queue.Queue()  # FIFO 를 쓰는 기본 큐

# python queue 라이브러리는 특이하게 enqueue, dequeue 가 아니라, put, get 으로 처리함

data_queue.put('good')  # enqueue 기능
data_queue.put(1)

print(data_queue.qsize())

data_queue.get()  # dequeue 기능

print(data_queue.qsize())
