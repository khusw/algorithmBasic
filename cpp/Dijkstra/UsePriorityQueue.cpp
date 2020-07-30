/*
    힙을 사용하여 다익 스트라 알고리즘 구현
    시간 복잡도를 O(NlogN) 으로 줄이기.

    CPP 의 queue STL 은 내부적으로 우선순위 큐를 포함하고 있는데,
    우선순위 큐의 경우 본래 힙을 사용하기 때문에
    queue STL 을 이용해서 우선순위 큐를 사용할 경우, 결국은 힙을 쓰는것과 동일
    그러므로 별도로 힙을 구현할 필요가 없음.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7];
// 노드가 6개인 상태에서 pair 형태로 자신과 연결된 노드를 표현하기 위한 변수

int d[7]; // 거리를 나타내는 최소 비용 배열

void dijkstra(int start)
{
    d[start] = 0;                      // 자기 자신에게 가는 비용은 당연히 0
    priority_queue<pair<int, int>> pq; // 힙 구조를 나타내는 변수
    pq.push(make_pair(start, 0));
    // 가까운 순서대로 처리하므로 큐를 이용함.

    while (!pq.empty())
    {
        int current = pq.top().first; // 인덱스 번호를 받아옴
        // 여기서 pair 의 first 는 index 를 의미하며,
        // pair 의 second 는 간선의 가중치 값을 의미한다.
        // 음수를 붙이는 이유는 짧은 것이 먼저 오도록 하기 위함이다.
        // STL 에서 제공하는 기본 Priority_queue 의 경우
        // max heap 기반으로 작성되기 때문에 제일 큰게 맨 앞에 온다.
        int distance = -pq.top().second;

        pq.pop();

        // 최단 거리가 아닌 경우 스킵한다.
        if (d[current] < distance)
            continue;

        for (int i = 0; i < a[current].size(); i++)
        {
            // 선택된 노드의 인접 노드
            int next = a[current][i].first;
            // 선택된 노드 거쳐서 인접 노드로 가는 비용
            int nextDistance = distance + a[current][i].second;

            // 기존의 최소 비용(d[next]) 보다 더 적은 비용을 갖는다면 교체
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
                // 음수의 값을 pq 에 넣은 이유는 기본적으로 pq 는 MaxHeap 기반으로 설계 되었으므로,
                // 큰 값이 위로 올라오기 때문이다.
            }
        }
    }
}

int main()
{
    // 여기서는 기본적으로 연결되지 않은 경우 비용을 모두 무한대로 취급함
    for (int i = 0; i <= number; i++)
    {
        d[i] = INF;
    }

    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(1);

    for (int i = 1; i <= number; i++)
    {
        printf("%d ", d[i]);
    }
}

/*
    이런식으로 우선순위 큐를 활용하여 시간복잡도를 
    O(NlogN) 으로 줄인 방식이 실제 PS 에서 더 많이 쓰이고 자주 사용됨
    아무래도 시간초과 문제 때문.
*/