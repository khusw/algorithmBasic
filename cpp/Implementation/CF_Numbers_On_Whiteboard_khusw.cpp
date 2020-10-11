/*
    C. Numbers on Whiteboard
    https://codeforces.com/contest/1430/problem/C
*/

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int T;

void solve(int n, double arr[]) {
    vector<pair<int, int>> vec;
    for (int i = n - 1; i > 0; i--) {
        int tmp = ceil((arr[i] + arr[i - 1]) / 2);
        vec.push_back(make_pair(arr[i - 1], arr[i]));
        arr[i - 1] = tmp;
        arr[i] = 0;
    }

    cout << arr[0] << "\n";
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        double arr[n];
        for (int j = 0; j < n; j++) {
            arr[j] = j + 1;
        }
        solve(n, arr);
    }

    return 0;
}