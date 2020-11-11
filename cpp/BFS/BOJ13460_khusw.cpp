/*
    BOJ 13460 구슬 게임 2
    https://www.acmicpc.net/problem/13460
*/

#include <bits/stdc++.h>

using namespace std;

int N, M;
int hy, hx, ry, rx, by, bx;  // hall y, hall x, red y, red x, blue y, blue x
string board[10];
queue<pair<int, int>> redBall;
queue<pair<int, int>> blueBall;
int dy[4] = {-1, 1, 0, 0};  // N S W E
int dx[4] = {0, 0, -1, 1};
bool visited[10][10][10][10];  // ry, rx, by, bx
bool isHall = false;
int answer;

void bfs() {
    visited[ry][rx][by][bx] = true;

    while (!redBall.empty()) {
        int redBallSize = redBall.size();

        while (redBallSize--) {
            ry = redBall.front().first;
            rx = redBall.front().second;

            by = blueBall.front().first;
            bx = blueBall.front().second;

            redBall.pop();
            blueBall.pop();

            if (answer > 10) break;

            if (ry == hy && rx == hx) {
                isHall = true;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nry = ry + dy[i];
                int nrx = rx + dx[i];

                int nby = by + dy[i];
                int nbx = bx + dx[i];

                // move red ball until # or O
                while (1) {
                    if (board[nry][nrx] == '#') {
                        nry -= dy[i];
                        nrx -= dx[i];
                        break;
                    }
                    if (board[nry][nrx] == 'O') break;
                    nry += dy[i];
                    nrx += dx[i];
                }

                // move blue ball until # or O
                while (1) {
                    if (board[nby][nbx] == '#') {
                        nby -= dy[i];
                        nbx -= dx[i];
                        break;
                    }
                    if (board[nby][nbx] == 'O') break;
                    nby += dy[i];
                    nbx += dx[i];
                }

                if (nby == hy && nbx == hx) continue;  // because blue can't enter hall

                if (nry == nby && nrx == nbx) {  // when two ball position is same, make them different.
                    switch (i) {
                        case 0:
                            ry > by ? nry++ : nby++;
                            break;
                        case 1:
                            ry < by ? nry-- : nby--;
                            break;
                        case 2:
                            rx > bx ? nrx++ : nbx++;
                            break;
                        case 3:
                            rx < bx ? nrx-- : nbx--;
                            break;
                    }
                }

                if (visited[nry][nrx][nby][nbx]) continue;
                visited[nry][nrx][nby][nbx] = true;
                redBall.push(make_pair(nry, nrx));
                blueBall.push(make_pair(nby, nbx));
            }
        }
        if (isHall)
            break;
        else
            answer++;
    }

    if (isHall)
        cout << answer << endl;
    else
        cout << "-1" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'R') {
                redBall.push(make_pair(i, j));
                ry = i;
                rx = j;
            }
            if (board[i][j] == 'B') {
                blueBall.push(make_pair(i, j));
                by = i;
                bx = j;
            }
            if (board[i][j] == 'O') {
                hy = i;
                hx = j;
            }
        }
    }

    bfs();

    return 0;
}