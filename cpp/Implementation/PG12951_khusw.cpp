/*
    PG 12951 JadenCase 문자열 만들기
    https://programmers.co.kr/learn/courses/30/lessons/12951
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    if ('a' <= s[0] && s[0] <= 'z') s[0] = (s[0] - 'a') + 'A';
    for (int i = 1; i < len; ++i) {
        if (s[i] == ' ' && i + 1 < len) {
            if ('a' <= s[i + 1] && s[i + 1] <= 'z') {
                s[i + 1] = (s[i + 1] - 'a') + 'A';
            }
        } else if ('A' <= s[i] && s[i] <= 'Z' && s[i - 1] != ' ') {
            s[i] = (s[i] - 'A') + 'a';
        }
    }
    answer = s;
    return answer;
}