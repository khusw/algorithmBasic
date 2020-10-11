/*
    BOJ 1700 멀티탭 스케줄링
    https://www.acmicpc.net/problem/1700
*/

#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
int schedule[101];  // 입력 배열
int plugin[101];    // 플러그인

void solve() {
    int cnt = 0;

    for (int i = 0; i < K; i++) {
        bool plugged_in = false;

        for (int j = 0; j < N; j++) {
            if (plugin[j] == schedule[i]) {
                plugged_in = true;
                break;
            }
        }

        if (plugged_in) continue;

        for (int j = 0; j < N; j++) {
            if (!plugin[j]) {
                plugin[j] = schedule[i];
                plugged_in = true;
                break;
            }
        }

        if (plugged_in) continue;

        int index, device_index = -1;
        for (int j = 0; j < N; j++) {
            int last_index = 0;
            for (int k = i + 1; k < K; k++) {
                if (plugin[j] == schedule[k]) break;
                last_index++;
            }

            if (last_index > device_index) {
                index = j;
                device_index = last_index;
            }
        }
        cnt++;
        plugin[index] = schedule[i];
    }

    cout << cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }

    solve();

    return 0;
}