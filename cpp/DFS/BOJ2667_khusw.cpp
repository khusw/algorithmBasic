/*
    BOJ 2667 단지번호 붙이기
    https://www.acmicpc.net/problem/2667
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, cnt;
int checked[25][25];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
string adj[25];
vector<int> answer;

void DFS(int i, int j) {
    checked[i][j] = true;
    cnt++;

    for (int k = 0; k < 4; k++) {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if ((0 <= newX && newX < n) && (0 <= newY && newY < n)) {
            if (adj[newX][newY] == '1' && !checked[newX][newY]) {
                DFS(newX, newY);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == '1' && !checked[i][j]) {
                cnt = 0;
                DFS(i, j);
                answer.push_back(cnt);
            }
        }
    }

    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}