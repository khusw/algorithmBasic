/*
    BOJ 16235 나무 재테크
    https://www.acmicpc.net/problem/16235
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> tree[11][11];
int land[11][11], nutrient[11][11];

int count_alive_trees() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cnt += tree[i][j].size();
    return cnt;
}

void seasons() {
    // spring, summer
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!tree[i][j].size()) continue;

            int dead_tree = 0;
            vector<int> temp;

            sort(tree[i][j].begin(), tree[i][j].end());

            for (int k = 0; k < tree[i][j].size(); ++k) {
                int tree_age = tree[i][j][k];
                if (land[i][j] >= tree_age) {
                    land[i][j] -= tree_age;
                    temp.push_back(tree_age + 1);
                } else {
                    dead_tree += (tree_age / 2);
                }
            }

            tree[i][j].clear();
            for (int k = 0; k < temp.size(); ++k)
                tree[i][j].push_back(temp[k]);
            land[i][j] += dead_tree;
        }
    }

    // autumn
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!tree[i][j].size()) continue;

            for (int k = 0; k < tree[i][j].size(); ++k) {
                int tree_age = tree[i][j][k];
                if (tree_age % 5 == 0) {
                    for (int w = 0; w < 8; ++w) {
                        int ny = i + dy[w], nx = j + dx[w];
                        if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }

    // winter
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            land[i][j] += nutrient[i][j];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> nutrient[i][j];
            land[i][j] = 5;
        }
    }

    for (int i = 0; i < M; ++i) {
        int y, x, z;
        cin >> y >> x >> z;
        tree[y][x].push_back(z);
    }

    for (int year = 0; year < K; ++year)
        seasons();

    int answer = count_alive_trees();
    cout << answer;

    return 0;
}