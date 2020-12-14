/*
    BOJ 14890 경사로
    https://www.acmicpc.net/problem/14890
*/

#include <cmath>
#include <iostream>

#define MAX 101

using namespace std;

int n, l, answer;
int adj[MAX][MAX], adj2[MAX][MAX];

bool is_valid(int map[MAX][MAX], int x, int y) {
    int temp = map[x][y + 1];
    for (int j = y + 1; j < y + 1 + l; ++j)
        if (map[x][j] != temp) return false;
    return true;
}

int cnt_road(int map[MAX][MAX]) {
    int total = 0;

    for (int i = 0; i < n; ++i) {
        bool flag = true;
        int cnt = 1;

        for (int j = 0; j < n - 1; ++j) {
            if (map[i][j] == map[i][j + 1])
                cnt++;
            else if (map[i][j] == map[i][j + 1] + 1) {
                if (is_valid(map, i, j)) {
                    j += (l - 1);
                    cnt = 0;
                } else {
                    flag = false;
                    break;
                }
            } else if (map[i][j] + 1 == map[i][j + 1]) {
                if (cnt >= l)
                    cnt = 1;
                else {
                    flag = false;
                    break;
                }
            } else if (abs(map[i][j] - map[i][j + 1]) >= 2) {
                flag = false;
                break;
            }
        }

        if (flag) total++;
    }

    return total;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            adj2[j][i] = adj[i][j];
        }
    }

    int num1 = cnt_road(adj);
    int num2 = cnt_road(adj2);

    cout << num1 + num2 << "\n";

    return 0;
}