/*
    BOJ 3190 Snake
    https://www.acmicpc.net/problem/3190
*/
#include <bits/stdc++.h>

#define endl "\n"
#define MAX 101

using namespace std;

int n, k, l;
int dx[4] = {0, 1, 0, -1};  // East South West North 순서
int dy[4] = {1, 0, -1, 0};
bool apple[MAX][MAX];
bool visited[MAX][MAX];
deque<pair<int, char>> snakeDir;

void solve() {
    int dir = 0, time = 0;
    deque<pair<int, int>> snake;
    snake.emplace_back(make_pair(0, 0));
    visited[0][0] = true;
    while (true) {
        time++;
        pair<int, int> head = snake.back();
        int nx = head.first + dx[dir];
        int ny = head.second + dy[dir];

        if (!((0 <= nx && nx < n) && (0 <= ny && ny < n)) || visited[nx][ny]) {
            cout << time << endl;
            break;
        }

        visited[nx][ny] = true;
        snake.emplace_back(make_pair(nx, ny));

        if (apple[nx][ny])
            apple[nx][ny] = false;
        else {
            pair<int, int> tail = snake.front();
            visited[tail.first][tail.second] = false;
            snake.pop_front();
        }

        if (snakeDir.size() && snakeDir.front().first == time) {
            if (snakeDir.front().second == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            snakeDir.pop_front();
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    int x, y;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        apple[x - 1][y - 1] = true;
    }

    cin >> l;
    for (int i = 0; i < l; ++i) {
        int num;
        char ch;
        cin >> num >> ch;
        snakeDir.emplace_back(make_pair(num, ch));
    }

    solve();

    return 0;
}