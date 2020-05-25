/*
    BFS (Breadth-First Search) 너비 우선 탐색
    특정 데이터 탐색시에 너비를 우선으로 탐색하는 알고리즘
    시작 점과 가까운것 위주로 탐색
    BFS 는 맹목적인 탐색을 할때 사용.
    BFS 는 최단 경로를 찾아주기 때문에 많이 사용.
    (미로 탐색 같은 문제에서 사용됨)
    큐와 그래프를 통해서 구현.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[8];         // checked (방문 여부를 나타내는 배열) 이것도 노드 번호가 1 부터여서 8개 잡음.
vector<int> a[8]; // 노드 번호가 1 부터 이기 때문에 8개로 지정

void bfs(int start)
{
    queue<int> q;
    q.push(start);   // 맨처음 노드의 값을 넣어줌
    c[start] = true; // 맨처음 노드를 방문 표시
    while (!q.empty())
    {                      // 큐가 비었을때 까지
        int x = q.front(); // 큐의 맨 앞 요소
        q.pop();
        cout << x << ' '; // 노드 번호 출력
        for (int i = 0; i < a[x].size(); i++)
        {
            int y = a[x][i];
            if (!c[y])
            {
                q.push(y);
                c[y] = true;
            }
        }
    }
}

int main()
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);
}

/*
    이 개념과 소스코드 5/22 다시 리뷰 해라

    BFS 자체만으로는 의미가 있는게 아니라, 
    다른 알고리즘 (최단경로 탐색, 크루스칼 등) 에 쓸수 있어야 한다.
*/

/*
    int n; // 노드 갯수
    int c[n + 1]; // 방문 여부 파악
    vector<int> adj[n + 1]; // 인접 행렬을 나타내는 2차원 배열 
    void bfs(int start) // start 는 시작 노드 번호임 
    {
        queue<int> q; 
        q.push(start); // 처음엔 시작노드를 방문했기에 start 를 push 함
        c[start] = true; // 방문 했기 때문에 true 처리

        while(!q.empty()) { // 큐가 비어있을 때 까지
            int x = q.front();
            q.pop();
            cout << x << ' '; // 큐에서 빠질 때 마다 출력.
            for(int i = 0; i < a[x].size(); i++) {
                // a 가 2차원 배열이므로 a[x].size() 로 계산
                int y = a[x][i];
                if(!c[y]) { // 방문한게 아니라면
                    q.push(y);
                    c[y] = true;
                }   
            }
        }
    }
*/