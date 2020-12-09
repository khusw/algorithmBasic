/*
    PG 70129 이진 변환 반복하기
    https://programmers.co.kr/learn/courses/30/lessons/70129
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int cnt = 0, zero = 0;
    while (s != "1") {
        cnt++;
        string temp;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') temp.push_back(s[i]);
            if (s[i] == '0') zero++;
        }

        int len = temp.length();
        temp = "";
        while (len != 0) {
            int num = len % 2;
            temp = temp + to_string(num);
            len /= 2;
        }

        s = temp;
    }
    answer[0] = cnt;
    answer[1] = zero;
    return answer;
}