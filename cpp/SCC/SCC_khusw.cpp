/*
    강한 결합 요소 (Strongly Connected Component)

    그래프 내에서 강하게 결합된 정접 집합을 뜻한다.
    동일한 SCC 에 속하는 두 vertex 는 서로 도달이 가능하다.

    강한 결합 요소인지 아닌지 판별하는 방법은
    임의의 두 정점을 잡아서 
    두 정점이 서로 연결이 되면 강한 결합 요소라고 부를 수 있다.
    A 노드에서 B 노드로만 갈수 있다던가 (단방향), 둘다 갈수있는 방향이 없다 던가(경로 없음) 그런 경우는
    SCC 라 부를 수 없다.

    간단히 말하면, 
    Cycle 이 발생하면, 무조건 SCC 다.
    또한 그래프의 종류가 방향성을 갖는 방향 그래프여야만 SCC 판별의 의미를 가짐
    방향성이 없는 무방향 그래프라면, 그냥 전체가 통으로 SCC 에 해당하게되어 
    아무 의미가 없어짐.

    SCC 를 그래프 내에서 추출하는 알고리즘은 두가지로 나뉨

    1. Kosaraju's Algorithm
    2. Tarjan's Algorithm

    1번이 2번보다 구현은 쉬우나, 2번을 사용할 때 SCC 찾는데에 있어서 적용이 더 쉬움

    이 예제에서는 Tarjan's Algorithm 을 사용하여 코드를 구현함
    Tarjan's Algorithm 은 모든 정점들에 대해서 DFS 를 수행해서 SCC 를 찾는 알고리즘임.
    DFS 를 이용해서 사이클을 찾을 때 보통 Union Find 알고리즘을 사용하며,
    여기서 그 개념이 사용됨.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001 // MAX 는 가능한 총 노드의 갯수를 의미함

using namespace std;

int id, d[MAX];          // 노드의 id 값과, distance 값을 담은 배열 변수
bool finished[MAX];      // DFS 로 방문 했는지 탐색이 끝났는지 판별
vector<int> adj[MAX];    // 인접 노드의 값을 담는 adjacent array
vector<vector<int>> SCC; // 2차원 배열로 SCC 를 표현한 것은 어떤 한 그래프 내에서 여러개의 사이클이 존재할 수 있기 때문.
stack<int> s;

// DFS 는 총 정점의 갯수 만큼 수행된다.
int DFS(int x)
{
    d[x] = ++id; // 노드 마다 고유의 번호를 갖게 설정, d[] 에는 부모의 노드 번호가 들어가게 됨
    s.push(x);   // 스택에 자기 자신을 넣음

    int parent = d[x];
    for (int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if (d[y] == 0)
            // 부모 노드 번호를 사이클 내에서 가장 작은 번호로 변경함.
            // 다만 이 경우는 DFS에 의해서 모두 방문 했을 때, 돌아가면서 부모 번호를 재 배열하는 곳이며,
            // 아직 방문하지 않은 이웃일 때
            parent = min(parent, DFS(y));
        else if (!finished[y])
            // 여기 조건문은 DFS 가 아직 끝나지 않았을 때 수행함
            // DFS 를 처리중인 이웃일때
            parent = min(parent, d[y]);
    }

    // 부모 노드가 자기 자신일 때 (즉, 사이클이 생성됬는지 확인 되는 지점)
    if (parent == d[x])
    {
        vector<int> scc;
        while (1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x)
                break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main()
{
    int v = 11;
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(7);
    adj[6].push_back(5);
    adj[7].push_back(6);
    adj[8].push_back(9);
    adj[9].push_back(10);
    adj[10].push_back(11);
    adj[11].push_back(3);
    adj[11].push_back(8);

    for (int i = 1; i <= v; i++)
    {
        // 1 번 노드 부터 모든 노드 까지 DFS 를 수행
        if (d[i] == 0)
            DFS(i); // 단 한번도 방문하지 않은 노드에 한해서 DFS 수행
    }
    printf("SCC 의 갯수 : %d\n", SCC.size());
    for (int i = 0; i < SCC.size(); i++)
    {
        printf("%d번째 SCC : ", i + 1);
        for (int j = 0; j < SCC[i].size(); j++)
        {
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
    이 기법은 위상정렬과 함께 사용되는것이 일반적
    단순히 SCC 자체로 문제가 나오거나 하지는 않는다.
    위상정렬을 수행할 때, 그래프를 SCC 를 통해서 그룹을 형성하고,
    그룹을 가지고 위상정렬을 수행하면 더 편하게 위상정렬을 할 수 있다.
    -> 대회에 많이 나오는 듯 일반 코테 보다는.

    SCC 의 시간복잡도는 O(V + E)
*/