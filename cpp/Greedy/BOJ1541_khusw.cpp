/*
    BOJ 1541 잃어버린 괄호
    https://www.acmicpc.net/problem/1541
*/

#include <bits/stdc++.h>

using namespace std;

string input, tmp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> input;

    int len = input.length(), answer = 0;
    bool check = false;
    for (int i = 0; i <= len; ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
            if (check)
                answer -= stoi(tmp);
            else
                answer += stoi(tmp);

            if (input[i] == '-') check = true;
            tmp = "";
            continue;
        }
        tmp += input[i];
    }

    cout << answer;

    return 0;
}