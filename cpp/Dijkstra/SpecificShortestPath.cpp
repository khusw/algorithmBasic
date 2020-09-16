/* 
    BOJ 1504 특정한 최단 경로
    https://www.acmicpc.net/problem/1504

    이 문제의 핵심은
    특정 지점을 반드시 지나게 하면서 동시에 최단 거리를 찾아가게 해야 함.
    이런 류의 문제의 경우,
    다익스트라 코드 자체를 바꾸기 보다는 그대로 두고
    다익스트라를 여러번 시도하여 값을 얻어내야함 (기존까지의 문제들은 한번 수행하면 끝)

    주어진 조건을 만족하기 위해서 다음의 시행을 거쳐야함
    1 -> A -> B -> N 
    1 -> B -> A -> N

    (A, B 는 반드시 거쳐야할 중간 노드)

    첫번째
    : 1에서 A 또는 B 를 가기 위한 최단 거리 값

    두번째
    : A 에서 B 로 가기 위한 최단 거리값
    (방향이 없는 그래프여서 A->B 나 B->A 나 가중치 값이 같다)

    세번째
    : A 에서 N 가기 위한 최단 거리 값

    네번째
    : B 에서 N 가기 위한 최단 거리 값

    이렇게 4개의 시행을 거쳐야 원하는 조건이 성립.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 801
#define INF 987654321
#define MIN(A, B) A > B ? B : A

using namespace std;
typedef pair<int, int> P;

int N, E, mid1, mid2, answer;
bool check, check2;
vector<pair<int, int>> adj[MAX];  // node 번호, 거리 순 으로 들어감
int dist[MAX];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;  // 거리 , 노드 번호 순으로 들어감
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();

        if (dist[node] < node_distance)
            continue;

        for (int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i].first;
            int next_node_distance = node_distance + adj[node][i].second;

            if (dist[next_node] > next_node_distance) {
                dist[next_node] = next_node_distance;
                pq.push(make_pair(next_node_distance, next_node));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= N; i++) dist[i] = INF;

    cin >> mid1 >> mid2;

    dijkstra(1);              // 시작 지점 부터 일단 순회
    int route1 = dist[mid1];  // 1 -> A 거리
    int route2 = dist[mid2];  // 1 -> B 거리

    if (route1 != INF) check = true;  // 1 -> A 최단 거리가 있다면 true 로 변환
    if (route2 != INF) check2 = true;

    for (int i = 1; i <= N; i++) dist[i] = INF;  // 거리 값은 항상 다시 리셋해야함.
    dijkstra(mid1);                              // A 를 시작점으로 하는 다익스트라 계산
    if (check) route1 += dist[mid2];             // 1 -> A -> B
    if (check2) route2 += dist[mid1];            // 1 -> B -> A

    for (int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(mid2);                // B 를 시작점으로 하는 다익스트라 계산
    if (check) route1 += dist[N];  // 1 -> A -> B -> N

    for (int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(mid1);                 // A 를 시작점으로 하는 다익스트라 계산
    if (check2) route2 += dist[N];  // 1 -> B -> A -> N

    if (!check && !check2)
        cout << "-1";
    else {
        answer = MIN(route1, route2);
        cout << answer;
    }

    return 0;
}