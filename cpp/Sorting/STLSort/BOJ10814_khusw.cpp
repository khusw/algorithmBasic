/*
    BOJ 10814 나이순 정렬
    https://www.acmicpc.net/problem/10814
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n;
vector<pair<int, string>> vec;

bool comp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int age;
        string name;
        cin >> age >> name;
        vec.push_back(make_pair(age, name));
    }

    stable_sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    return 0;
}