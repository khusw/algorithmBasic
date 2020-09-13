/*
    가장 단순무식하게 문자열 매칭을 하는 알고리즘
    O(N * M) 이 소요되는 방식.
*/

#include <iostream>
#include <string>

using namespace std;

int cnt;

void search_str(string& str, string& pattern) {
    int str_size = str.length();
    int pattern_size = pattern.length();
    bool check = false;

    for (int i = 0; i <= str_size - pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
            if (str[i + j] == pattern[j])
                check = true;
            else {
                check = false;
                break;
            }
        }
        if (check)
            cnt++;
    }
}

int main() {
    string str = "ABCABABCDE";
    string pattern = "ABC";

    search_str(str, pattern);

    cout << cnt;  // 결과 2

    return 0;
}