#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321, SWITCHES = 10, CLOCKS = 16;

const char adj[SWITCHES][CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."};

int t;

bool vaild_aligned(const vector<int>& clocks) {
    for (int i = 0; i < clocks.size(); ++i) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

void push_switch(vector<int>& clocks, int number) {
    for (int clock = 0; clock < CLOCKS; ++clock) {
        if (adj[number][clock] == 'x') {
            clocks[clock] += 3;
            if (clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int number) {
    if (number == SWITCHES) return vaild_aligned(clocks) ? 0 : INF;
    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(clocks, number + 1));
        push_switch(clocks, number);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        vector<int> clocks(16);
        for (int i = 0; i < 16; ++i) cin >> clocks[i];
        int answer = solve(clocks, 0);
        if (answer == INF)
            cout << "-1\n";
        else
            cout << answer << "\n";
    }

    return 0;
}