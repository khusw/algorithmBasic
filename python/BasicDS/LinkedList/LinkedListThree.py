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

    def delete(self, data):  # 노드를 삭제하기 위한 함수
        if self.head == "":
            print("there is no node")
            return

        if self.head.data == data:  # head 를 지우려 할 때
            temp = self.head
            self.head = self.head.next
            del temp  # python 은 객체 인스턴스 지울때 del 사용
        else:  # head 가 아닌 다른 데이터를 지울 때 (중간, 끝)
            node = self.head
            while node.next:
                if node.next.data == data:
                    temp = node.next
                    node.next = node.next.next
                    del temp
                    return  # 찾아서 삭제 했으므로 리턴
                else:
                    node = node.next  # 다음 loop 를 돌기 위한 구문


linkedlist1 = NodeMgmt(0)
linkedlist1.add(1)
linkedlist1.add(2)
linkedlist1.add(3)

for index in range(4, 11):
    linkedlist1.add(index)

linkedlist1.desc()

'''
    노드 삭제
    : head 를 삭제하는 경우, 중간 노드를 삭제하는 경우, 마지막 노드를 삭제하는 경우    
'''

linkedlist2 = NodeMgmt(0)
print(linkedlist2.head)

# head 를 지우는 경우
linkedlist2.delete(0)  # head 값 0 을 제거

for index in range(1, 5):
    linkedlist2.add(index)

linkedlist2.desc()  # 전체 1 ~ 5 출력

linkedlist2.delete(4)  # 4를 삭제 (중간 노드 삭제)

linkedlist2.desc()  # 4 를 제외한 1,2,3,5 를 출력
