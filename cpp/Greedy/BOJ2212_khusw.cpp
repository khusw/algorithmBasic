/*
    BOJ 2212 Sensor
    https://www.acmicpc.net/problem/2212
*/
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> vec, distList;

bool comp(int& a, int& b) {
    return a > b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    if (k >= n) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int total = vec[n - 1] - vec[0];

    for (int i = 0; i < n - 1; ++i)
        distList.push_back(vec[i + 1] - vec[i]);

    sort(distList.begin(), distList.end(), comp);

    for (int i = 0; i < k - 1; ++i)
        total -= distList[i];

    cout << total;

    return 0;
}