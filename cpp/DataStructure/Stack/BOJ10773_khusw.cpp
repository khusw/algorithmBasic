/*
    BOJ 10773 Zero
    https://www.acmicpc.net/submit/10773/23744576
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int k, num, answer;
stack<int> st;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> num;
        if (num == 0)
            st.pop();
        else
            st.push(num);
    }

    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    cout << answer << endl;

    return 0;
}