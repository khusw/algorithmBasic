/*
    BOJ 17144 미세먼지 안녕
    https://www.acmicpc.net/problem/17144
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int map[MAX][MAX], copy_map[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> aircon_pos;
int R, C, T, answer;

void map_copy() {
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            copy_map[i][j] = map[i][j];
}

void map_copy2() {
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            map[i][j] = copy_map[i][j];
}

int count_dust() {
    int cnt = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (map[i][j] > 0)
                cnt += map[i][j];
    return cnt;
}

void turn_on_air_purifier() {
    for (int i = 0; i < 2; ++i) {
        int y = aircon_pos[i].first, x = aircon_pos[i].second;
        if (i == 0) {
            // move right
            map[y][x + 1] = 0;
            for (int j = x + 1; j < C - 1; ++j) map[y][j + 1] = copy_map[y][j];

            // move top
            for (int j = y - 1; j >= 0; --j) map[j][C - 1] = copy_map[j + 1][C - 1];

            // move left
            for (int j = C - 2; j >= 0; --j) map[0][j] = copy_map[0][j + 1];

            // move down
            for (int j = 1; j < y; ++j) map[j][0] = copy_map[j - 1][0];
        } else if (i == 1) {
            // move right
            map[y][x + 1] = 0;
            for (int j = x + 1; j < C - 1; ++j) map[y][j + 1] = copy_map[y][j];

            // move down
            for (int j = y + 1; j < R; ++j) map[j][C - 1] = copy_map[j - 1][C - 1];

            // move left
            for (int j = C - 2; j >= 0; --j) map[R - 1][j] = copy_map[R - 1][j + 1];

            // move top
            for (int j = R - 2; j > y; --j) map[j][0] = copy_map[j + 1][0];
        }
    }
}

void spread_dust() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (map[i][j] > 0) {
                int temp = map[i][j] / 5, count_spread;
                vector<pair<int, int>> vec;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == -1) continue;
                    vec.push_back({ny, nx});
                }

                count_spread = vec.size();
                for (int k = 0; k < count_spread; ++k) {
                    int ny = vec[k].first, nx = vec[k].second;
                    copy_map[ny][nx] += temp;
                }
                copy_map[i][j] = copy_map[i][j] - temp * count_spread;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> map[i][j];
            if (map[i][j] == -1) aircon_pos.push_back({i, j});
        }
    }

    while (T--) {
        map_copy();
        spread_dust();
        map_copy2();
        turn_on_air_purifier();
    }

    answer = count_dust();
    cout << answer;

    return 0;
}