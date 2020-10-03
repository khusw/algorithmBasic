/*
    BOJ 2606 바이러스
    https://www.acmicpc.net/problem/2606
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, cnt;
int checked[101];
vector<int> adj[101];

void BFS(int start) {
    queue<int> q;
    q.push(start);
    checked[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < adj[x].size(); i++) {
            int y = adj[x][i];
            if (!checked[y]) {
                q.push(y);
                checked[y] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int couple;
    cin >> couple;

    int x, y;

    for (int i = 0; i < couple; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    BFS(1);

    printf("%d", cnt - 1);
    return 0;
}