'''
    Linked List 는 
    포인터로 다른 노드를 가르켜서 연결하는 형태

    직접 하나 하나 구현할 수 있어야함. 

    배열의 단점은 미리 사용할 메모리 양을 지정해야함
    (메모리 양이 유동적이지 못함)

    Linked List 는 메모리를 유동적으로 사용할 수 있도록 바꾼 구조
    (배열의 단점을 극복한 형태)

    Linked List 는 data + pointer 로 구성되어 있다.
    Node = data + pointer 

    Linked List 는 연속된 메모리 공간을 차지하는 형태가 아니라
    아무 주소 값이나 잡아서 각 노드에게 부여하고,
    그후에 노드 간 연결을 위해서 포인터로 각각을 가르킨다.
'''

# node 의 구현


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# node 간 연결 (포인터를 사용한)
node1 = Node(1)
node2 = Node(2)
node1.next = node2

head = node1  # 가장 맨앞의 node 가 누구인가를 나타내기 위한 변수 head

# 데이터 추가하기.


def add(data):
    node = head  # 첫 노드 설정
    while node.next:  # 다음 노드가 존재하는 경우
        node = node.next  # node 변수를 다음 노드 값으로 지정
    node.next = Node(data)  # 다음 노드가 없는 경우 data 의 값으로 설정


for index in range(3, 10):
    add(index)


# 노드에 들어간 데이터 출력

def printAll():
    node = head  # 첫 노드를 설정
    while node.next:
        print(node.data)
        node = node.next
    print(node.data)


printAll()
