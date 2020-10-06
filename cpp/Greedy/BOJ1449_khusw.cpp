/*
    BOJ 1449 수리공 항승
    https://www.acmicpc.net/problem/1449
*/

#include <iostream>
#define MAX 1001

using namespace std;

int N, L;
int arr[MAX];

int count() {
    int i = 0, cnt = 0;
    while (i < MAX) {
        if (arr[i] != 0) {
            i += L;
            cnt++;
        } else {
            i++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }

    cout << count();

    return 0;
}