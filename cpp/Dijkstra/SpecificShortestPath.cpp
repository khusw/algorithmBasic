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

    여기서는 dijkstra(시작점, 끝점)
    으로 처리해서
    1 -> A 의 값
    A -> B 의 값
    B -> N 의 값 을 구하는 방식으로 처리했다.
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

int N, E, A, B, answer;
vector<pair<int, int>> adj[MAX];  // node 번호, 거리 순 으로 들어감

int dijkstra(int start, int end) {
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;  // 거리 , 노드 번호 순으로 들어감
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i].first;
            int next_node_distance = node_distance + adj[node][i].second;

            if (dist[next_node] > next_node_distance) {
                dist[next_node] = next_node_distance;
                pq.push(make_pair(next_node_distance, next_node));
            }
        }
    }
    return dist.at(end);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool check1 = true;
    bool check2 = true;

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    cin >> A >> B;

    int start_a = dijkstra(1, A);  // 1 -> A
    int a_b = dijkstra(A, B);      // A -> B
    int b_N = dijkstra(B, N);      // B -> N

    if (start_a == INF || a_b == INF || b_N == INF) check1 = false;  // 여기까지가 1 -> A -> B -> N 에 대한 검증

    int start_b = dijkstra(1, B);  // 1 -> B
    int b_a = dijkstra(B, A);      // B -> A
    int a_N = dijkstra(A, N);      // A -> N

    if (start_b == INF || b_a == INF || a_N == INF) check2 = false;

    if (check1 && check2) {
        int case1 = start_a + a_b + b_N;
        int case2 = start_b + b_a + a_N;
        answer = MIN(case1, case2);
    } else {
        answer = -1;
    }

    cout << answer;

    return 0;
}