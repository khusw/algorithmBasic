'''
    Linked List 의 장단점

    장점은 배열처럼 정해진 데이터 공간을 할당하지 않아도 사용가능하다는 점
    단점은 pointer 를 위한 별도의 주소 공간이 필요하기 때문에 저장공간의 효율 자체가 높은 편은 아니고,
    연결된 주소 위치를 찾는데 있어서 접근 시간이 필요하므로 접근 속도가 늦어짐
    또한 중간 노드 삭제시 연결을 재구성해야됨
'''


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


node1 = Node(1)
node2 = Node(2)
node1.next = node2

head = node1


def add(data):
    node = head
    while node.next:
        node = node.next
    node.next = Node(data)


for i in range(3, 10):
    add(i)


def printAll():
    node = head
    while node.next:
        print(node.data)
        node = node.next
    print(node.data)

# 노드 중간에 데이터를 넣는 방법


node3 = Node(1.5)  # 1 과 2 사이에 넣어보기 위한 값

node = head
Search = True
while Search:
    if node.data == 1:
        Search = False
    else:
        node = node.next

node_next = node.next
node.next = node3
node3.next = node_next

printAll()
