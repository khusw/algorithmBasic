/*
    BOJ 1913 달팽이
    https://www.acmicpc.net/problem/1913

    이차원 배열의 중간 좌표부터 시작해서 
    달팽이 모양으로 채워나가는 문제

*/

#include <iostream>
#define MAX 1000

using namespace std;

int N, pos;
long adj[MAX][MAX];

void print_adj() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}

pair<int, int> find_pos(int pos) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] == pos) {
                return make_pair(i + 1, j + 1);
            }
        }
    }
}

void make_snail(int N) {
    int left_limit = 0, top_limit = 0;              // 좌, 상 한계점
    int right_limit = N - 1, bottom_limit = N - 1;  // 우, 하 한계점
    for (int row = 0, col = 0, cnt = N * N; cnt >= 1; cnt--) {
        if (row < bottom_limit && col == left_limit) {
            // 아래로 이동 (N = 3 일때, row 는 0, 1 에 값 넣고 2 일때 다음 if 로 넘어감)
            adj[row++][col] = cnt;
        } else if (col < right_limit && row == bottom_limit) {
            // 오른쪽 이동 (N = 3 일때, col 은 0, 1 에 값 넣고 2 일때 다음 if 로 넘어감)
            adj[row][col++] = cnt;
        } else if (row > top_limit && col == right_limit) {
            // 위로 이동 (N = 3 일때, row = 2, col = 2 에서 처음 시작하고, row = 0, col = 2 에서 다음 if 로 넘어감 이때 4까지 채움)
            adj[row--][col] = cnt;
        } else if (col > left_limit && row == top_limit) {
            // 좌측으로 이동
            adj[row][col--] = cnt;
            if (col == left_limit + 1) {
                left_limit++, top_limit++, right_limit--, bottom_limit--;  // 왼쪽 과 위쪽 에 대한 리미트를 하나 늘리고 오른쪽과 아래에 대한 리미트를 하나 줄인다 그래서 전체적인 크기를 하나 줄일수 있음
            }
        } else if (row == top_limit && row == bottom_limit) {
            // 위와 아래의 리미트가 같으면 마지막 1 값이 들어가는 지점.
            adj[row][col] = cnt;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    cin >> pos;
    make_snail(N);
    print_adj();
    cout << find_pos(pos).first << " " << find_pos(pos).second;
    return 0;
}