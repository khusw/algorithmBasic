'''
    OOP 로 LinkedList 구현
'''

# 기본 노드 클래스


class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

# 노드들을 관리하는 node management 클래스


class NodeMgmt:
    def __init__(self, data):
        self.head = Node(data)  # 초기 head node 설정

    def add(self, data):
        if self.head == "":
            self.head = Node(data)
        else:
            node = self.head  # 처음 노드 설정
            while node.next:
                node = node.next  # 다음 노드가 null 일 때 까지 반복
            node.next = Node(data)  # null 인 부분에 추가.

    def desc(self):  # 처음 부터 끝까지 노드를 순회하는 함수 (출력용)
        node = self.head
        while node.next:
            print(node.data)
            node = node.next
        print(node.data)


linkedlist1 = NodeMgmt(0)
linkedlist1.add(1)
linkedlist1.add(2)
linkedlist1.add(3)

for index in range(4, 11):
    linkedlist1.add(index)

linkedlist1.desc()
