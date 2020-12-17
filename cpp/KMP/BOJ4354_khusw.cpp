/*
    BOJ 4354 문자열 제곱
    https://www.acmicpc.net/problem/4354
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> make_fail_func(string pattern) {
    int pattern_size = pattern.size();
    vector<int> fail(pattern_size, 0);

    for (int i = 1, j = 0; i < pattern_size; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j]) fail[i] = ++j;
    }

    return fail;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        string pattern;
        cin >> pattern;

        if (pattern.size() == 1 && pattern[0] == '.') break;

        vector<int> vec = make_fail_func(pattern);
        int len = vec.size() - 1;

        if (pattern.size() % (pattern.size() - vec[len]) != 0)
            cout << "1\n";
        else
            cout << pattern.size() / (pattern.size() - vec[len]) << "\n";
    }

    return 0;
}