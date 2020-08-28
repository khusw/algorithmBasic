/*
    BOJ 1697 숨바꼭질
    https://www.acmicpc.net/problem/1697

    BFS 를 이용해서 세가지의 케이스를 통과해야되는 문제
*/

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int N, K, cnt;
int checked[MAX];

void bfs(int num) {
    queue<int> q;
    q.push(num);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            // 큐 사이즈 만큼 돌리는 이유는
            // 큐 내부의 값들에 대해서 +1, -1, *2 를 수행해야 하기 때문이다.
            int x = q.front();
            q.pop();
            if (x == K) {
                cout << cnt << '\n';
                return;
            }
            if (x > 0 && !checked[x - 1]) {
                checked[x - 1] = true;
                q.push(x - 1);
            }
            if (x < MAX - 1 && !checked[x + 1]) {
                checked[x + 1] = true;
                q.push(x + 1);
            }
            if (x * 2 < MAX && !checked[2 * x]) {
                checked[2 * x] = true;
                q.push(2 * x);
            }
        }
        cnt++;  // 큐 사이즈 만큼 한바퀴 돌면 다음 초로 넘어감.
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    bfs(N);

    return 0;
}