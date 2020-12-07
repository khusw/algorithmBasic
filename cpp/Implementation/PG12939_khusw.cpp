/*
    PG 12939 최댓값과 최솟값
    https://programmers.co.kr/learn/courses/30/lessons/12939
*/

#include <algorithm>
#include <string>

#define INF 987654321
#define INF2 -987654321

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length(), min_num = INF, max_num = INF2;

    for (int i = 0; i < len; ++i) {
        int temp = 0, j;
        string str = "";

        if (s[i] != ' ') {
            for (j = i; j < len; ++j) {
                if (s[j] != ' ')
                    str.push_back(s[j]);
                else
                    break;
            }
        }

        i = j;
        if (str != "") {
            temp = stoi(str);
            min_num = min(min_num, temp);
            max_num = max(max_num, temp);
        }
    }

    string min_str, max_str;
    min_str = to_string(min_num);
    max_str = to_string(max_num);

    answer = min_str + " " + max_str;
    return answer;
}