/*
    BOJ 2108 통계학 
    https://www.acmicpc.net/problem/2108
*/

#include <bits/stdc++.h>

#define MAX 500001

using namespace std;

int n, tmp, maxFreq;
vector<int> arr, freq(8001, 0);

void solve() {
    int avg, mid, mostFreq = -1, range, sum = 0;

    for (int i = 0; i < n; ++i) sum += arr[i];
    avg = round(sum / (double)n);

    sort(arr.begin(), arr.end());
    mid = arr[round(n / 2)];
    range = arr[n - 1] - arr[0];

    bool isSecond = false;
    for (int i = -4000; i < 4001; ++i) {
        tmp = (i <= 0) ? abs(i) : i + 4000;
        if (freq[tmp] == maxFreq) {
            mostFreq = i;
            if (isSecond) break;
            isSecond = true;
        }
    }

    cout << avg << "\n";
    cout << mid << "\n";
    cout << mostFreq << "\n";
    cout << range << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
        tmp = (num <= 0) ? abs(num) : abs(num + 4000);
        freq[tmp]++;
        if (freq[tmp] > maxFreq) maxFreq = freq[tmp];
    }

    solve();

    return 0;
}