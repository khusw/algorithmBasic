/*
    BOJ 17143 낚시왕
    https://www.acmicpc.net/problem/17143
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

struct Shark {
    int y;
    int x;
    int speed;
    int dir;  // up : 1, down : 2, right : 3, left : 4
    int size;
    int number;
};

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};
int R, C, M, answer;
vector<int> map[MAX][MAX];
vector<Shark> shark_list;

bool comp(int a, int b) {
    if (shark_list[a].size > shark_list[b].size) return true;
    return false;
}

bool check() {
    for (int i = 0; i < shark_list.size(); ++i)
        if (shark_list[i].size != 0) return false;
    return true;
}

void kill_shark() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (map[i][j].size() > 1) {
                sort(map[i][j].begin(), map[i][j].end(), comp);
                int live = map[i][j][0];
                for (int k = 1; k < map[i][j].size(); ++k) {
                    shark_list[map[i][j][k]].size = 0;
                    shark_list[map[i][j][k]].y = -1;
                    shark_list[map[i][j][k]].x = -1;
                }
                map[i][j].clear();
                map[i][j].push_back(shark_list[live].number);
            }
        }
    }
}

void move_shark() {
    for (int i = 0; i < shark_list.size(); ++i) {
        if (shark_list[i].size == 0) continue;
        int r = shark_list[i].y, c = shark_list[i].x;
        map[r][c].clear();
    }

    for (int i = 0; i < shark_list.size(); ++i) {
        if (shark_list[i].size == 0) continue;
        int r = shark_list[i].y, c = shark_list[i].x;
        int direction = shark_list[i].dir;
        int velocity = shark_list[i].speed;

        if (direction == 1 || direction == 2) {
            int rotate = (R - 1) * 2;
            if (velocity >= rotate) velocity %= rotate;

            for (int j = 0; j < velocity; ++j) {
                int ny = r + dy[direction];
                int nx = c + dx[direction];
                if (ny < 1) {
                    direction = 2;
                    ny += 2;
                }
                if (ny > R) {
                    direction = 1;
                    ny -= 2;
                }
                r = ny;
                c = nx;
            }
        } else {
            int rotate = (C - 1) * 2;
            if (velocity >= rotate) velocity %= rotate;

            for (int j = 0; j < velocity; ++j) {
                int ny = r + dy[direction];
                int nx = c + dx[direction];
                if (nx < 1) {
                    direction = 3;
                    nx += 2;
                }
                if (nx > C) {
                    direction = 4;
                    nx -= 2;
                }
                r = ny;
                c = nx;
            }
        }
        shark_list[i].y = r;
        shark_list[i].x = c;
        shark_list[i].dir = direction;
        map[r][c].push_back(i);
    }
}

void catch_shark(int col) {
    for (int row = 1; row <= R; ++row) {
        if (map[row][col].size() != 0) {
            answer += shark_list[map[row][col][0]].size;
            shark_list[map[row][col][0]].size = 0;
            map[row][col].clear();
            break;
        }
    }
}

void solve() {
    for (int i = 1; i <= C; ++i) {
        if (check()) break;
        catch_shark(i);
        move_shark();
        kill_shark();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark_list.push_back({r, c, s, d, z, i});
        map[r][c].push_back(i);
    }

    if (M == 0) {
        cout << 0;
        return 0;
    }

    solve();

    cout << answer;

    return 0;
}