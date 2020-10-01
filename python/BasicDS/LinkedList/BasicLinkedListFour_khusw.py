'''
    노드 데이터가 특정 숫자인 노드를 찾는 함수를 생성한 코드
'''

# 기본 노드 클래스


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# 노드 관리 클래스


class NodeMgmt:
    def __init__(self, data):
        self.head = Node(data)  # 초기 헤드 노드 설정

    def add(self, data):
        # 노드를 추가하는 함수 (처음, 중간, 끝 에 따라 달라짐)
        if self.head == "":
            self.head = Node(data)  # 첫 노드가 없을때
        else:
            node = self.head
            while node.next:
                if node.data < data and node.next.data > data:
                    newNode = Node(data)
                    temp = node.next
                    node.next = newNode
                    newNode.next = temp
                    return
                else:
                    node = node.next
            node.next = Node(data)  # 끝에만 추가하는 방식

    def delete(self, data):
        if self.head == "":
            print("There is no node")
            return

        if self.head.data == data:
            temp = self.head
            self.head = self.head.next
            del temp
        else:
            node = self.head
            while node.next:
                if node.next.data == data:
                    temp = node.next
                    node.next = node.next.next
                    del temp
                    return
                else:
                    node = node.next

    def desc(self):
        if self.head == "":
            print("There is no node")
            return
        else:
            node = self.head
            while node.next:
                print(node.data)
                node = node.next
            print(node.data)

    def find(self, data):
        if self.head == "":
            print("There is no node")
            return
        else:
            if self.head == data:
                print("find : ", self.head.data)
            else:
                node = self.head
                while node.next:
                    if node.next.data == data:
                        print("find : ", node.next.data)
                        return
                    else:
                        node = node.next


linkedList1 = NodeMgmt(0)
linkedList1.add(1)
linkedList1.add(2)
linkedList1.add(3)
linkedList1.add(4)
linkedList1.add(3.5)

linkedList1.desc()

linkedList1.find(3)


'''
    다양한 linked list 의 구조

    Doubly Linked List

    기존 Linked List 의 단점은
    어떤 데이터를 찾을 때 간에 항상 첫 노드부터 탐색을 시작해야 함
    즉 완전탐색을 할 수 밖에 없는 구조. 탐색의 비용이 많이 드는 경우가 있다는 뜻.

    Doubly Linked List 는 앞에서만 탐색하지 말고
    뒤에서 탐색을 할 수 있게 만들면 어떻겠냐는게 메인 아이디어.
    이 자료구조는 이전 데이터 주소 포인터,
    다음 데이터 주소 포인터 두개를 가지고 있음
    즉 노드가 3개의 영역을 갖고 있는 것
    (이전주소, 현데이터, 다음주소)
'''

# Doubly Linked List 기본 노드


class DoubleNode:
    def __init__(self, data, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next

# Doubly Linked List 관리 노드


class DNodeMgmt:
    def __init__(self, data):
        self.head = DoubleNode(data)
        self.tail = self.head
        # 최초의 노드는 head 이면서, tail 임.

    def insert(self, data):
        if self.head == None:
            self.head = DoubleNode(data)
            self.tail = self.head
        else:
            node = self.head
            while node.next:
                node = node.next
            newNode = Node(data)
            node.next = newNode
            newNode.prev = node
            self.tail = newNode

    def search_from_head(self, data):
        if self.head == None:
            return False
        node = self.head
        while node:
            if node.data == data:
                return node
            else:
                node = node.next
        return False

    def search_from_tail(self, data):
        node = self.tail
        while node:
            if node.data == data:
                return node
            else:
                node = node.prev
        return False

    def desc(self):
        if self.head == None:
            print("There is no node")
            return
        else:
            node = self.head
            while node.next:
                print(node.data)
                node = node.next
            print(node.data)


doublyLinkedList1 = DNodeMgmt(0)
doublyLinkedList1.insert(1)
doublyLinkedList1.insert(10)
doublyLinkedList1.insert(100)
doublyLinkedList1.insert(1000)
doublyLinkedList1.insert(50)

print("Doubly Linked List ")
doublyLinkedList1.desc()
print(doublyLinkedList1.search_from_head(109))
print(doublyLinkedList1.search_from_tail(8))
