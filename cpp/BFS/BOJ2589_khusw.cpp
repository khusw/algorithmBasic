/*
    보물섬 (BOJ 2589)
    https://www.acmicpc.net/problem/2589
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define MAX 51

using namespace std;

int initX, initY, maxValue;
string adj[MAX];
int checked[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int sum[MAX][MAX];

void BFS(int i, int j) {
    queue<pair<int, int>> pos;
    checked[i][j] = true;
    pos.push({i, j});

    while (!pos.empty()) {
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if ((0 <= newX && newX < initX) && (0 <= newY && newY < initY)) {
                if (adj[newX][newY] == 'L' && !checked[newX][newY]) {
                    checked[newX][newY] = true;
                    pos.push({newX, newY});
                    sum[newX][newY] = sum[x][y] + 1;
                    maxValue = max(maxValue, sum[newX][newY]);
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> initX >> initY;

    for (int i = 0; i < initX; i++) {
        cin >> adj[i];
    }

    for (int i = 0; i < initX; i++) {
        for (int j = 0; j < initY; j++) {
            if (adj[i][j] == 'L' && !checked[i][j]) {
                BFS(i, j);
                memset(checked, 0, sizeof(checked));
                memset(sum, 0, sizeof(sum));
            }
        }
    }

    printf("%d", maxValue);
    return 0;
}