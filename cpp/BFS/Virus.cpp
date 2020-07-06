/*
    바이러스 (백준 2606 번)

    연결된 노드에게 바이러스가 전파되는데
    전파 방식이 BFS 로 전달됨.

    입력은 첫번째 줄에는 노드의 총 갯수가 주어지고,
    둘째 줄에는 서로 연결된 노드간의 쌍의 갯수가 주어지며,
    그 이후줄 입력에는 연결된 쌍의 정보가 입력으로 주어진다.

    출력은 1번 노드(시작 노드) 가 바이러스에 걸렸을 때, 1번을 통해서 바이러스에 걸리게 되는 노드의 수를 출력.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, cnt;           // 총 노드 갯수, 출력을 위한 결과를 나타내는 변수
int checked[101];     // 방문 여부를 나타내는 배열
vector<int> adj[101]; // 인접 노드를 나타내는 이차원 배열

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    checked[start] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < adj[x].size(); i++)
        {
            int y = adj[x][i];
            if (!checked[y])
            {
                // 방문하지 않은 경우라면
                q.push(y);
                checked[y] = true;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n; // 전체 노드의 갯수

    int couple; // 쌍의 갯수
    cin >> couple;

    int x, y; // 입력으로 받게될 노드들

    // 한칸 띄어서 입력이 들어올 때는 그냥 cin >> A >> B 로 처리 가능하다.
    for (int i = 0; i < couple; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    BFS(1); // 문제에서 1번 컴퓨터가 걸렸다고 가정함.

    printf("%d", cnt - 1); // 1번 컴퓨터는 빼고 계산
    return 0;
}