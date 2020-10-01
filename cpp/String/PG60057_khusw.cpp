/*
    프로그래머스 문자열 압축
    https://programmers.co.kr/learn/courses/30/lessons/60057
*/

#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;

    for (int i = 1; i <= len / 2; i++) {
        int size = s.length();
        for (int j = 0; j < len; j++) {
            for (int cnt = 0, z = i; j + z < len; z += i) {
                if (s.substr(j, i) == s.substr(j + z, i))
                    cnt++;
                else {
                    size -= i * cnt;
                    if (cnt) size += to_string(cnt + 1).length();
                    j += z - 1;
                    break;
                }
                if (j + z + i >= len) {
                    size -= i * cnt;
                    size += to_string(cnt + 1).length();
                    j += z;
                }
            }
        }
        if (size < answer) answer = size;
    }
    return answer;
}

int main() {
    string str = "aabbaccc";
    int ans = solution(str);
    cout << ans;
    return 0;
}