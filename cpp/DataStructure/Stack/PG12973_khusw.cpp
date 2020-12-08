/*
    PG 12973 짝지어 제거하기
    https://programmers.co.kr/learn/courses/30/lessons/12973
*/

#include <stack>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    for (int i = 0; i < s.length(); ++i) {
        if (!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }

    if (st.empty()) answer = 1;

    return answer;
}