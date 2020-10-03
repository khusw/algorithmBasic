/*
    BOJ 2309 일곱 난쟁이
    https://www.acmicpc.net/problem/2309
*/

#include <algorithm>
#include <iostream>

using namespace std;

int keys[9];
int sum;
bool checked;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        cin >> keys[i];
        sum += keys[i];
    }

    for (int x = 0; x < 9; x++) {
        if (checked) break;
        for (int y = 0; y < 9; y++) {
            if (keys[x] == keys[y]) continue;
            if (sum - keys[x] - keys[y] == 100) {
                checked = true;
                keys[x] = 0;
                keys[y] = 0;
                break;
            }
        }
    }

    sort(keys, keys + 9);

    for (int i = 0; i < 9; i++) {
        if (keys[i] != 0) {
            cout << keys[i] << '\n';
        }
    }

    return 0;
}