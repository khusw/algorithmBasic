/*
    BOJ 1018 체스판 다시 칠하기
    https://www.acmicpc.net/problem/1018
*/

#include <algorithm>
#include <iostream>
#define MAX 51

using namespace std;

int N, M, answer;
char adj[MAX][MAX];

int make_black_chess(int i, int j) {
    // 시작 정점이 black 일때
    int cnt = 0;
    for (int x = i; x < i + 8; x++) {
        for (int y = j; y < j + 8; y++) {
            if (x == i || x == i + 2 || x == i + 4 || x == i + 6) {
                // 행이 짝수 일때
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    // 행이 짝수이면서 동시에 열이 짝수인 경우, 검은색이어야함
                    if (adj[x][y] != 'B') cnt++;
                } else {
                    // 행이 짝수이면서 동시에 열이 홀수인 경우, 흰색이어야함.
                    if (adj[x][y] != 'W') cnt++;
                }
            } else {
                // 행이 홀수 일때
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    // 행이 홀수 이면서 동시에 열이 짝수인경우, 흰색이어야함
                    if (adj[x][y] != 'W') cnt++;
                } else {
                    // 행이 홀수 이면서 동시에 열이 홀수인경우, 검은색이어야함
                    if (adj[x][y] != 'B') cnt++;
                }
            }
        }
    }
    return cnt;
}

int make_white_chess(int i, int j) {
    // 시작정점이 white 일때
    int cnt = 0;
    for (int x = i; x < i + 8; x++) {
        for (int y = j; y < j + 8; y++) {
            if (x == i || x == i + 2 || x == i + 4 || x == i + 6) {
                // 행이 짝수일때
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    // 행이 짝수이면서 동시에 열이 짝수인경우, 흰색이어야함
                    if (adj[x][y] != 'W') cnt++;
                } else {
                    // 행이 짝수이면서 동시에 열이 홀수인경우, 검은색이어야함
                    if (adj[x][y] != 'B') cnt++;
                }
            } else {
                // 행이 홀수 번수 일때
                if (y == j || y == j + 2 || y == j + 4 || y == j + 6) {
                    // 행이 홀수이면서 동시에 열이 짝수인경우, 검은색이어야함
                    if (adj[x][y] != 'B') cnt++;
                } else {
                    // 행이 홀수이면서 동시에 열이 홀수인경우, 흰색이어야함
                    if (adj[x][y] != 'W') cnt++;
                }
            }
        }
    }
    return cnt;
}

int make_chess() {
    int total_min = 987654321;
    int white_min, black_min;
    for (int i = 0; i < N; i++) {
        if (N < i + 8) break;
        for (int j = 0; j < M; j++) {
            if (M < j + 8) break;
            white_min = make_white_chess(i, j);
            black_min = make_black_chess(i, j);
            total_min = min(total_min, min(white_min, black_min));
        }
    }
    if (total_min == 0) total_min = 1;
    return total_min;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }
    answer = make_chess();
    cout << answer;
    return 0;
}

/*
    문제를 잘못이해하고 있었음
    짜르는 갯수를 구하는게 아니라,
    짜르고 나서 칠해야되는 갯수의 최소값

    그리고 브루트 포스 문제이면서 최대 값이 50 by 50 이므로
    이중 포문을 돌려서 단순 무식하게 반복해도 통과함.

    그리고 매크로 함수로 #define MIN 은 단 한번만 수행됨
    연속으로 MIN(A, MIN(B, C)) 가 불가능함
    왜 이런건지는 모르겠으나 그냥 algorithm 헤더 파일 쓰든가
    함수를 따로 선언하든가 하는게 나을듯
*/