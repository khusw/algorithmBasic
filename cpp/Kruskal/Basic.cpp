/*
    Kruskal Algorithm 은 최소의 비용으로 모든 노드를 연결하기 위해 사용되는 알고리즘이다.
    즉, 최소 비용 신장 트리를 만들기 위한 알고리즘이다.
    여러개의 도시가 있을 때, 각 도시를 도로를 통해서 연결 하려 할 때,
    최소한의 비용으로만 연결을 시도할 때 사용되는 알고리즘이다.

    용어
    노드 = 정점 = 도시 = vertex = node  
    간선 = 거리 = 비용 = edge = weight

    최소 비용으로 그래프 상의 모든 노드를 연결하기 위해서는
    간선의 최대 갯수가 노드 - 1 이어야 한다.

    크루스칼 알고리즘의 핵심 개념은
    "간선을 거리가 짧은 순서대로 그래프에 포함시킨다" 이다.
    모든 노드를 최대한 적은 비용으로 연결만 시키면 되므로,
    모든 간선의 정보를 오름차순으로 정렬한 뒤, 비용이 적은 간선부터
    차근차근 그래프에 포함시키는 방식으로 풀어나간다.
    (단 사이클이 형성 되어선 안됨)
    -> 그러므로
    1. 정렬된 순서에 맞게 그래프에 포함시키고
    2. 포함시키기 전에 사이클 테이블을 확인해서 사이클을 만드는지 확인하고,
    3. 사이클을 형성하는 경우 간선을 포함시키지 않아야 한다.

    사이클 발생 여부 판별 방법은
    Union-Find 알고리즘을 사용해야 찾을 수 있다.

    처음에는 연결된 노드 번호와 그에 따른 간선 weight 를 나타낸다

    예를들면,

    1 | 7  4 | 7  1 | 5   .... 이런 식으로 노드 번호 | 노드 번호 으로 표현
     12     13     17                            가중치값

    처음에는 부모 노드의 값을 각자 자기자신의 번호로 설정한다.
    노드 번호 | 1 2 3 4 5 6 ..
    부모 번호 | 1 2 3 4 5 6 ..

    이 데이터들을 표현하기 이전에 앞서서,
    간선들에 대한 데이터값을 오름차순으로 정렬했다는 전제가 필요함.

    크루스칼 알고리즘을 구현하기 위해서는 먼저
    Union-Find 알고리즘을 사용해야 하므로,
    Union-Find 에서 사용했던 함수들을 그대로 가져와서 사용한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x) // 부모 노드 번호를 반환하는 함수
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) // 부모 병합을 위한 코드
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) // 작은 값으로 변경시키기 위한 비교문
        parent[b] = a;
    else
        parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    else
        return 0;
}

// 간선 정보를 담는 간선 클래스 선언
class Edge
{
public:
    int node[2];  // 두 노드 번호를 갖는 배열
    int distance; // weight 값을 담는 변수
    Edge(int a, int b, int distance)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(Edge &edge)
    {
        return this->distance < edge.distance;
    }
};

int main()
{
    int n = 7;
    int m = 11;
    vector<Edge> v;

    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(5, 7, 73));

    // 간선의 비용을 기준으로 오름차순 정렬 실시
    // 별도의 정렬 함수를 넣지 않은 이유는 Edge 클래스에 operator < 에 대한 정의가 있기 때문
    sort(v.begin(), v.end());

    // 각 정점이 포함된 그래프가 어디인지 저장.
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // 사이클이 발생하지 않는 경우 그래프에 포함해야함
        if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
        {
            // 두 노드가 같은 부모를 갖는게 아니라면, 사이클이 발생하지 않음
            // 같은 부모를 갖고 있는 상황에서 unionParent 를 수행하게 되면, 사이클이 발생 할 수 있음.
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }

    printf("%d\n", sum);
}

/*
    자주 나오므로 꼭 외워야 함.
*/