/*
	BOJ 11721 열 개씩 끊어 출력 
	https://www.acmicpc.net/problem/11721 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        cout << s[i];
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }

    return 0;
}