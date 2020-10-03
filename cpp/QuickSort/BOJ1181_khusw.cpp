/*
    BOJ 1181 문자열 정렬
    https://www.acmicpc.net/problem/1181
*/

#include <algorithm>
#include <iostream>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return 1;
    } else if (a.length() > b.length()) {
        return 0;
    } else {
        return a < b;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue;
        } else {
            cout << a[i] << '\n';
        }
    }
}