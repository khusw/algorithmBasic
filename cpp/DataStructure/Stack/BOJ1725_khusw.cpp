/*
    BOJ 1725 Histogram
    https://www.acmicpc.net/problem/1725
*/

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;    // histogram's index
int arr[100002];  // histogram's height
int N, answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    st.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int height = arr[st.top()];
            st.pop();
            int width = i - st.top() - 1;

            answer = max(answer, height * width);
        }
        st.push(i);
    }

    cout << answer;

    return 0;
}