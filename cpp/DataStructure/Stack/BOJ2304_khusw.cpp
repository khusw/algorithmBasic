/*
    BOJ 2304 창고 다각형
    https://www.acmicpc.net/problem/2304
*/

#include <iostream>
#include <stack>

using namespace std;

int N, first = 1001, last, longest, pos, len, answer;
int arr[1001];
stack<int> st;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    while (N--) {
        cin >> pos >> len;
        arr[pos] = len;
        if (last < pos) last = pos;
        if (first > pos) first = pos;
        if (len > arr[longest]) longest = pos;
    }

    for (int i = first; i <= longest; i++) {
        if (arr[i]) {
            if (st.empty())
                st.push(arr[i]);
            else if (arr[i] > st.top())
                st.push(arr[i]);
        }
        answer += st.top();
    }

    while (!st.empty()) st.pop();

    for (int i = last; i > longest; i--) {
        if (arr[i]) {
            if (st.empty())
                st.push(arr[i]);
            else if (arr[i] > st.top())
                st.push(arr[i]);
        }
        answer += st.top();
    }

    cout << answer;

    return 0;
}