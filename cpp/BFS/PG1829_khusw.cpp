/*
    PG 1829 카카오프렌즈 컬러링북
    https://programmers.co.kr/learn/courses/30/lessons/1829
*/

#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[101][101];

int bfs(int y, int x, vector<vector<int>>& adj, int m, int n) {
    int cnt = 1;
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if ((0 <= ny && ny < m) && (0 <= nx && nx < n)) {
                if (adj[y][x] == adj[ny][nx] && !visited[ny][nx]) {
                    q.push(make_pair(ny, nx));
                    cnt++;
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && picture[i][j] != 0) {
                int temp = bfs(i, j, picture, m, n);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, temp);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}