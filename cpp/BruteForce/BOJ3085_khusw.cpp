/*
    BOJ 3085 사탕 게임
    https://www.acmicpc.net/problem/3085
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int answer;

int max_cnt(vector<string>& vec_str) {
    int vec_len = vec_str.size();
    int result = 1;

    for (int i = 0; i < vec_len; i++) {
        int cnt = 1;
        int str_len = vec_str[i].length();
        for (int j = 0; j < str_len - 1; j++) {
            if (vec_str[i][j] == vec_str[i][j + 1]) {
                cnt++;
            } else {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    for (int i = 0; i < vec_len; i++) {
        int cnt = 1;
        int str_len = vec_str[i].length();
        for (int j = 0; j < str_len - 1; j++) {
            if (vec_str[j][i] == vec_str[j + 1][i]) {
                cnt++;
            } else {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    return result;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    vector<string> in_str;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        in_str.push_back(str);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            swap(in_str[i][j], in_str[i][j + 1]);
            answer = max(answer, max_cnt(in_str));
            swap(in_str[i][j], in_str[i][j + 1]);

            swap(in_str[j][i], in_str[j + 1][i]);
            answer = max(answer, max_cnt(in_str));
            swap(in_str[j][i], in_str[j + 1][i]);
        }
    }

    printf("%d", answer);

    return 0;
}
