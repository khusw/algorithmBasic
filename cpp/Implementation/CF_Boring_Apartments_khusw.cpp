/*
    A. Boring Apartment
    https://codeforces.com/contest/1433/problem/0
*/

#include <iostream>
#include <string>

using namespace std;

int T;
string arr[36];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string str = "1";
    arr[0] = str;
    for (int i = 1; i < 36; i++) {
        char ch = str[0];
        if (str.length() < 4) {
            str.push_back(ch);
            arr[i] = str;
        } else {
            ch++;
            str = ch;
            arr[i] = str;
        }
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        string x;
        cin >> x;

        int len = 0;
        for (int j = 0; j < 36; j++) {
            len += arr[j].length();
            if (arr[j] == x) {
                cout << len << "\n";
                break;
            }
        }
    }

    return 0;
}