/*
    BOJ 4949 균형 잡힌 세상
    https://www.acmicpc.net/problem/4949
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        string str;
        stack<char> st;
        int smallCnt = 0, largeCnt = 0;

        getline(cin, str);

        if (str == ".") break;

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                smallCnt++;
                st.push(str[i]);
            }

            if (str[i] == '[') {
                largeCnt++;
                st.push(str[i]);
            }

            if (str[i] == ']') largeCnt--;
            if (str[i] == ')') smallCnt--;

            if (!st.empty() && str[i] == ')' && st.top() == '(') st.pop();

            if (!st.empty() && str[i] == ']' && st.top() == '[') st.pop();
        }

        if (st.empty() && largeCnt == 0 && smallCnt == 0)
            cout << "yes" << endl;
        else if (!st.empty())
            cout << "no" << endl;
        else if (st.empty() && (largeCnt != 0 || smallCnt != 0))
            cout << "no" << endl;
    }

    return 0;
}