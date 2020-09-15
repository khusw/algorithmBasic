/*
    BOJ 1753 최단거리
    https://www.acmicpc.net/problem/1753

    다익스트라 알고리즘은
    어떤 한 정점에서 다른 모든 정점들에 대한 최단거리를 계산하는 알고리즘이다.
    1753번 문제는 가장 기본 다익스트라 알고리즘에 대한 이해를 묻는 문제이다.

    입력으로
    첫번째 줄에 정점의 갯수 V, 간선의 갯수 E 가 주어진다
    (1<= V <= 20,000 , 1 <= E <= 300,000)
    정점의 번호는 1 ~ v 값으로 매겨져 있다.
    (간선 최대가 30만 이므로 우선순위 큐, 힙을 이용한 알고리즘을 써야만 시간 초과를 만화할 수 있다.)

    두번째 줄 입력에는 시작 정점의 번호 k 가 주어지며 (1 <= k <= v)

    세번째 줄 입력 부터는 e 개의 줄에 걸쳐 각 간선을 나타내는 세개의 정수
    u, v, w 가 순서대로 주어진다.
    u 에서 v 로 가는 가중치 값이 w 라는 의미가 된다.
    (u, v 는 서로 다르게 주어지며, w 는 10 이하의 자연수로 나타난다.)

    또한 서로 다른 두 정점 사이에 여러개의 간선이 존재할 수도 있다.

    출력은 첫째 줄 부터 v 개의 줄에 걸쳐, i 번째 줄에 i 번 정점으로의 최단 경로의 경로 값을 출력한다.
    시작점 자신은 0으로 출력하고, 경로가 없는 경우 INF 를 출력한다.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E, K;
int INF = 987654321;
int checked[20001];
vector<pair<int, int>> adj[20001];
int dist[20001];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int distance = -pq.top().first;  // 최대 힙이라서 최소힙으로 바꾸기 위해 - 붙임
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < distance)
            continue;

        for (int i = 0; i < adj[current].size(); i++)  // adj[cur].size 만큼 돌리는 것은 인접 노드에 대한 거리 정보를 가져오기 위함
        {
            int next = adj[current][i].first;
            int nextDistance = distance + adj[current][i].second;

            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;  // dist 배열에 대한 실질적 갱신이 이뤄지는 부분
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }

    return 0;
}