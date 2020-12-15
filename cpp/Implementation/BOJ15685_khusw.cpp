/*
    BOJ 15685 Dragon Curve
    https://www.acmicpc.net/problem/15685
*/

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int n, answer;
int x, y, d, g;
int adj[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> pos;

int count_square() {
    int cnt = 0;
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            if (adj[i][j] == 1 && adj[i][j + 1] == 1 && adj[i + 1][j] == 1 && adj[i + 1][j + 1] == 1) cnt++;
    return cnt;
}

void make_dragon_curve() {
    int size = pos.size();
    for (int i = size - 1; i >= 0; --i) {
        int nd = (pos[i] + 1) % 4;
        y = y + dy[nd];
        x = x + dx[nd];
        adj[y][x] = 1;
        pos.push_back(nd);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        pos.clear();

        cin >> x >> y >> d >> g;

        adj[y][x] = 1;
        y = y + dy[d];
        x = x + dx[d];
        adj[y][x] = 1;

        pos.push_back(d);
        for (int j = 0; j < g; ++j) make_dragon_curve();
    }

    answer = count_square();
    cout << answer;

    return 0;
}