/*
    B. Yet Another Bookshelf
    https://codeforces.com/contest/1433/problem/B
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int T;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, oneCnt = 0, zeroCnt = 0;
        cin >> n;
        string str;
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            str.push_back(ch);
            if (ch == '1')
                oneCnt++;
        }

        if (oneCnt == 1) {
            cout << 0 << "\n";
            continue;
        };

        int len = str.length();
        int start = 0, end = 0;
        for (int j = 0; j < len; j++) {
            if (str[j] == '1') {
                start = j;
                break;
            }
        }

        for (int j = len - 1; j > -1; j--) {
            if (str[j] == '1') {
                end = j;
                break;
            }
        }

        for (int j = start; j <= end; j++) {
            if (str[j] == '0') zeroCnt++;
        }

        cout << zeroCnt << "\n";
    }

    return 0;
}