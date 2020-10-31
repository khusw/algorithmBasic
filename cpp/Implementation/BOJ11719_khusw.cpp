/*
	BOJ 11719 그대로 출력하기 2 
	https://www.acmicpc.net/problem/11719 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s[100];
    for (int i = 0; i < 100; ++i) getline(cin, s[i]);

    for (int i = 0; i < 100; ++i) cout << s[i] << "\n";

    return 0;
}