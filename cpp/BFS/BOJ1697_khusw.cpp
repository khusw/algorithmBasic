/*
    BOJ 1697 숨바꼭질
    https://www.acmicpc.net/problem/1697
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
        cnt++;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    bfs(N);

    return 0;
}