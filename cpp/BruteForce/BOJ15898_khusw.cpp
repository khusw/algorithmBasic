/*
    BOJ 15898 피아의 아틀리에 신비한 대회의 연금술사
    https://www.acmicpc.net/problem/15898
*/

#include <bits/stdc++.h>

using namespace std;

int n, answer;
vector<vector<pair<int, char>>> adj(5, vector<pair<int, char>>(5, {0, 'W'}));
pair<int, char> ingredients[10][4][4][4];
bool visited[10];

int cnt_quaility(vector<vector<pair<int, char>>> vec) {
    int r = 0, b = 0, g = 0, y = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (vec[i][j].second == 'R') r += vec[i][j].first;
            if (vec[i][j].second == 'B') b += vec[i][j].first;
            if (vec[i][j].second == 'G') g += vec[i][j].first;
            if (vec[i][j].second == 'Y') y += vec[i][j].first;
        }
    }
    return 7 * r + 5 * b + 3 * g + 2 * y;
}

vector<vector<pair<int, char>>> insert_ingredient(vector<vector<pair<int, char>>> vec, int y, int x, int type, int dir) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            vec[y + i][x + j].first += ingredients[type][dir][i][j].first;

            if (vec[y + i][x + j].first < 0)
                vec[y + i][x + j].first = 0;
            else if (vec[y + i][x + j].first > 9)
                vec[y + i][x + j].first = 9;

            if (ingredients[type][dir][i][j].second != 'W')
                vec[y + i][x + j].second = ingredients[type][dir][i][j].second;
        }
    }
    return vec;
}

void turn_ingredient(int type, int dir) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ingredients[type][dir][i][j].first = ingredients[type][dir - 1][3 - j][i].first;
            ingredients[type][dir][i][j].second = ingredients[type][dir - 1][3 - j][i].second;
        }
    }
}

void brute_forces(vector<vector<pair<int, char>>> vec, int cnt) {
    if (cnt == 3) {
        answer = max(answer, cnt_quaility(vec));
        return;
    }

    for (int t = 0; t < n; ++t) {
        if (!visited[t]) {
            visited[t] = true;

            for (int i = 0; i <= 1; ++i) {
                for (int j = 0; j <= 1; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        vector<vector<pair<int, char>>> temp = insert_ingredient(vec, i, j, t, d);
                        brute_forces(temp, cnt + 1);
                    }
                }
            }

            visited[t] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int t = 0; t < n; ++t) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                int num;
                cin >> num;
                ingredients[t][0][j][k].first = num;
            }
        }

        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                char ch;
                cin >> ch;
                ingredients[t][0][j][k].second = ch;
            }
        }

        for (int d = 1; d <= 3; ++d) {
            turn_ingredient(t, d);
        }
    }

    brute_forces(adj, 0);
    cout << answer;

    return 0;
}