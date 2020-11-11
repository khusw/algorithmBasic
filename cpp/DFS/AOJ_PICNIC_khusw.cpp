/*
    AOJ PICNIC 소풍
    https://algospot.com/judge/problem/read/PICNIC
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int T, N, M;
int y, x, answer;
bool areFriends[10][10];
bool taken[10];  // taken 은 i 번째 학생이 짝을 찾았는지 여부를 나타내는 배열

int countPairings() {
    // base case
    int first = -1;
    for (int i = 0; i < N; ++i) {
        if (!taken[i]) {
            first = i;
            break;
        }
    }

    if (first == -1) return 1;

    int ret = 0;
    for (int second = first + 1; second < N; ++second) {
        if (!taken[first] && !taken[second] && areFriends[first][second]) {
            taken[first] = taken[second] = true;
            ret += countPairings();
            taken[first] = taken[second] = false;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        memset(taken, false, sizeof(taken));
        memset(areFriends, false, sizeof(areFriends));
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            cin >> y >> x;
            areFriends[y][x] = true;
            areFriends[x][y] = true;
        }
        answer = countPairings();
        cout << answer << endl;
    }

    return 0;
}