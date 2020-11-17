/*
    BOJ 18111 Mine Craft
    https://www.acmicpc.net/problem/18111
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int n, m, b;
int arr[257];
int minNum = INF, maxNum = -1;
int answerTime = INF, answerHeight = -1;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> b;

    for (int i = 0; i < n * m; ++i) {
        int num;
        cin >> num;
        arr[num]++;
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
    }

    for (int k = minNum; k <= maxNum; ++k) {
        int need = 0, inven = b, time = 0;
        for (int i = minNum; i <= maxNum; ++i) {
            if (i > k) {  // 기준 높이보다 클때
                inven += (i - k) * arr[i];
                time += (i - k) * arr[i] * 2;
            } else if (i < k) {
                need += (k - i) * arr[i];
                time += (k - i) * arr[i];
            }
        }

        if (need <= inven && answerTime >= time) {
            answerTime = time;
            answerHeight = k;
        }
    }

    cout << answerTime << " " << answerHeight;

    return 0;
}