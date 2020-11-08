/*
    BOJ 10799 쇠막대기
    https://www.acmicpc.net/problem/10799
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

stack<char> st;
string input;
int result;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(')
            st.push(input[i]);
        else {
            st.pop();
            if (input[i - 1] == '(')
                result += st.size();
            else
                result += 1;
        }
    }

    cout << result << endl;

    return 0;
}