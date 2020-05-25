/*
    그래프 탐색
    그래프를 탐색한다는 것은 어떤 vertex 에서 시작해서
    차례대로 다른 모든 vertex 를 한번씩 방문하는 방법론을 말한다.
    그래프 탐색에는 두가지 방법이 있다.
    DFS, BFS
    DFS 란 깊이 우선 탐색 (depth-first-search) 로 루트 노드에서 시작해서
    다음 분기로 넘어가기 전에 지금 있는 분기의 노드를 모두 완벽하게 탐색하는 방법

    DFS 는 모든 노드를 방문하려고 할때 사용되는 방법이다.
    검색 속도 자체는 BFS 보다는 느리다.

    DFS 는 자기 자신을 호출하는 순환 알고리즘의 형태를 갖고 있으며,
    DFS 를 쓸때 주의할 점은 어떤 노드를 방문 했었는지 여부를 반드시 검사해야 된다는것.

    DFS 는 탐색을 함에 있어서 보다 깊은 것을 우선적으로 탐색
    이 DFS 는 맹목적으로 각 노드를 탐색할때 주로 사용
    DFS 에서는 stack 을 사용하여 구현
    DFS 는 특이하게, 컴퓨터 자체가 기본적으로 스택의 원리를 사용해서 구현 되기 때문에
    재귀함수만으로 구현할 수도 있음.
    PS 에서도 재귀함수로 많이 구현하는 듯
*/

#include <iostream>
#include <vector>

using namespace std;

int num = 7;
int c[7];           // 배열 c 는 방문 여부를 검증하기 위한 배열임 = visited
vector<int> adj[8]; // 각 노드의 인접노드를 의미하는 vector = adj

void dfs(int x) // x 는 방문할 노드의 인덱스 번호임
{
    if (c[x])
        return;       // c[x] 라는 것은 그 노드의 방문여부를 말하며, 방문했으면 true 가 되므로 1 이 되어서 return
    c[x] = true;      // 이미 방문한게 아니라 지금 함수를 실행해서 방문 한 거라면 true 로 지정을 해줌
    cout << x << ' '; // 몇번째인지 보이기 위해 출력
    for (int i = 0; i < adj[x].size(); i++)
    {
        // 각 노드의 인접노드를 방문하기 위한 반복문
        int y = adj[x][i]; // 방문할 노드 x 의 인접노드 i 에 대한 인덱스 번호 호출
        dfs(y);            // 인접 노드에 대한 DFS 실시
    }
}

int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[2].push_back(5);
    adj[5].push_back(2);

    adj[3].push_back(6);
    adj[6].push_back(3);

    adj[3].push_back(7);
    adj[7].push_back(3);

    adj[6].push_back(7);
    adj[7].push_back(6);

    dfs(1);
    return 0;
}

/*
    DFS를 활용해서 코테 문제 나오는 경우 많으니 꼭 반드시 이해 해야함.

    다시 정리하면 DFS 는 스택과 그래프로 구현 가능
    (컴퓨터 자체가 스택 구조를 쓰기 때문에 굳이 스택을 쓰지 않아도 되긴함)

    1. 스택 최상단 노드를 확인한다
    2. 최상단 노드에서 방문하지 않은 인접 노드가 있다면 그 노드를 스택에 넣고 방문 처리
    (인접노드를 모두 다 방문한 경우라면, 최상단 노드를 스택에서 제거)
    이 작업을 계속 반복하는게 DFS

    void dfs(int start) {
        if(c[x]) return; // 방문을 당연히 안했기 때문에 초기화 값 false 로 인해 처음엔 return 되지 않음
        c[x] = true;
        cout << x << ' ';
        for (int i = 0; i < adj[x].size(); i++) {
            // 루트 노드 x 의 인접 노드를 확인하는 반복문
            int y = adj[x][i]; // 인접 노드의 번호
            dfs(y); // 재귀함수로 구현한 것은 인접 노드 자기자신의 인접노드에 대한 DFS 를 수행해야 하기 때문.
        } 
    }

    DFS, BFS 는 다른 그래프 알고리즘 구현을 위해서
    사용되는 일종의 툴 같은 거라 생각하면됨
    
*/