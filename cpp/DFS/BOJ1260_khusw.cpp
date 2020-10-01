/*
    BOJ 1260 (DFS 와 BFS)
    https://www.acmicpc.net/problem/1260

    그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하는 문제
    방문할 수 있는 정점이 여러개일 경우, 정점 번호가 더 작은 것을 먼저 탐색하고, 더이상 방문할수 있는 점이 없으면 종료함
    정점의 번호는 1번 부터 N번 까지이다.

    입력 값으로 N (정점의 갯수), M (간선의 갯수), V (탐색 시작을 위한 정점 번호) 가 주어진다.
    두번째 줄 입력 부터는 간선이 연결하는 두 정점의 번호가 주어지며, 총 M 개가 주어진다. 

    출력은 첫번째 줄에 DFS 수행 결과를, 두번째 줄에 BFS 수행 결과를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, M, V;
int checked[1001]; // 노드의 방문 여부만 확인하면 되므로 이차원 배열일 필요가 없음.
vector<int> adj[1001];

void bfs(int node)
{
    queue<int> q;
    checked[node] = true;
    q.push(node);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        sort(adj[x].begin(), adj[x].end());
        for (int i = 0; i < adj[x].size(); i++)
        {
            int y = adj[x][i];
            if (!checked[y])
            {
                q.push(y);
                checked[y] = true;
            }
        }
    }
}

void dfs(int node)
{
    if (checked[node])
        return;
    checked[node] = true;
    cout << node << ' ';
    sort(adj[node].begin(), adj[node].end());
    for (int i = 0; i < adj[node].size(); i++)
    {
        int y = adj[node][i];
        dfs(y);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(V);
    memset(checked, 0, sizeof(checked));
    cout << '\n';
    bfs(V);

    return 0;
}