'''
    BFS (Breadth First Search) Algorithm

    시작 정점으로부터, 가까이 근접해있는 노드를 먼저 방문하는 방식으로,
    멀리 떨어져 있을수록, 나중에 방문을 한다.
    wide 하게 탐색하는 방법

   두 노드 사이의 최단 경로나 임의의 경로를 찾고자 할 때 주로 쓰인다.
   친구 관계를 그래프로 표현한다고 할 때,
   DFS 로 탐색을 한다고 하면, 모든 노드를 전부 탐색해서 관계를 파악해야되고,
   BFS 의 경우, 시작 노드에서 가장 가까운 친구 관계를 탐색해서 탐색을 처리한다.
   즉 일부 구간만 탐색을 하는 경우 DFS 보다는 BFS 가 더 유용하다는 것이다.

   BFS 는 보통 Queue 를 사용해서 구현. 

   1. 시작노드를 방문한다
   -> 큐에 노드를 넣고, 방문 체크를 한다.

   2. 큐에서 꺼낸 노드와 인접한 노드를 모두 방문한다.
   -> 방문 체크를 하고, 큐에 넣는다
   -> 인접 노드가 없으면, 큐의 앞(front)에서 노드를 꺼낸다

   3. 큐가 비어 있을 때 까지 반복한다.

   아래의 예제는 BFS 로 전체 노드를 다 탐색하는게 아니라
   일부 노드만 탐색해서 그 결과 값을 배열로 리턴하는 문제를 구현한다
   예를 들면 A에서 시작해서 E로 갈려 할 때,
   A->B->E (가중치 합 : 3),
   A->C->E (가중치 합 : 6),의 두가지 경로가 있다 하면,
   [3, 6] 이 리턴되도록 만든다
   자기자신의 노드로 가면 0, 갈수 없는 노드로 향하면 -1이다.
   노드간 방향은 단 방향이다.
'''
from queue import Queue


def search(start, end):
    if start == end:
        lengthList.append(0)
        return

    q = Queue()
    q.put(start)
    checked[start] = True
    summation = 0  # 한 경로의 합을 표현

    while(not(q.empty())):
        x = q.get()  # x 는 시작, 중간 노드가 됨
        print(x, end=" ")
        for i in range(len(adj[x])):
            y = adj[x][i]
            if y == -1:
                continue  # -1 이면 갈 수 있는 경로가 없다
            if not(checked[y]):
                q.put(y)
                checked[y] = True
                summation += y
                if y == end:
                    summation += y
                    lengthList.append(summation)
                    checked[y] = False
                    summation = 0

    if len(lengthList) == 0:
        lengthList.append(-1)  # 아무것도 없다는 뜻은 경로가 없다는 뜻이다.
        return


n = 5
checked = [False for i in range(n)]
adj = [
    [0, 2, 4, -1, -1],  # A
    [-1, 0, -1, 1, 1],  # B
    [-1, -1, 0, -1, 2],  # C
    [-1, -1, -1, 0, 3],  # D
    [-1, -1, -1, -1, 0],  # E
]
lengthList = []  # 가중치 합 결과를 담은 배열
search(0, 4)
print(lengthList)
# A B C D E 5개의 노드가 있다고 가정하고 가중치는 임의로 설정
# adj 의 0 은 자기자신 노드를 의미하고, -1 은 연결되지 않은 노드임
