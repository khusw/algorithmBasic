/*
	SWEA 2819 격자판의 숫자 이어 붙이기
	https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB&categoryId=AV7I5fgqEogDFAXB&categoryType=CODE 
*/

#include <cstring>
#include <iostream>

#define endl "\n"

using namespace std;

int cnt, T;
int result[10000000];
int adj[4][4];

void dfs(int y, int x, int num, int depth) {
    if (depth == 7) {
        result[num] = 1;
        return;
    }

    num *= 10;
    num += adj[y][x];

    if (y - 1 >= 0) dfs(y - 1, x, num, depth + 1);  // N
    if (y + 1 < 4) dfs(y + 1, x, num, depth + 1);   // S
    if (x - 1 >= 0) dfs(y, x - 1, num, depth + 1);  // W
    if (x + 1 < 4) dfs(y, x + 1, num, depth + 1);   // E
}

int main(int argc, char** argv) {
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cnt = 0;
        memset(result, 0, sizeof(result));
        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> adj[i][j];

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                dfs(i, j, 0, 0);

        for (int i = 0; i < 10000000; ++i) {
            if (result[i] != 0) cnt++;
        }

        cout << "#" << test_case << " " << cnt << endl;
    }

    return 0;
}