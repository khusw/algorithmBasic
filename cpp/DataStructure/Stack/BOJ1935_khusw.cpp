/*
    BOJ 1935 후위 표기식2
    https://www.acmicpc.net/problem/1935
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<double> st;
string input;
double result;
double a_idx, b_idx;
int arr[27];
int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> input;

    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < input.length(); i++) {
        if ('A' <= input[i] && input[i] <= 'Z') {
            int num = input[i] - 'A';
            st.push(arr[num]);
        } else {
            b_idx = st.top();
            st.pop();
            a_idx = st.top();
            st.pop();
            if (input[i] == '*')
                st.push(a_idx * b_idx);
            else if (input[i] == '/')
                st.push(a_idx / b_idx);
            else if (input[i] == '+')
                st.push(a_idx + b_idx);
            else if (input[i] == '-')
                st.push(a_idx - b_idx);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();

    return 0;
}