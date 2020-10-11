/*
    A. Avoid Zero
    https://codeforces.com/contest/1427/problem/0
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;

bool comp(int a, int b) {
    return a > b;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
        sum += num;
    }

    if (sum == 0) {
        cout << "NO\n";
    } else if (sum > 0) {
        sort(a.begin(), a.end(), comp);
        cout << "YES\n";
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << "\n";
    } else if (sum < 0) {
        sort(a.begin(), a.end());
        cout << "YES\n";
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << "\n";
    }

    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}