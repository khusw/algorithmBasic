/*
    BOJ 9012 번 괄호
    https://www.acmicpc.net/problem/9012
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;
stack<char> stk;

string VPS(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            count += 1;
        } else {
            count -= 1;
        }
    }

    if (count == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        cout << VPS(str) << '\n';
    }
}