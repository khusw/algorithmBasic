/*
    BOJ 5525 IOIOI
    https://www.acmicpc.net/problem/5525
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, answer;
string pattern, parent;

void make_pattern() {
    int count_i = 0, count_o = 0;
    while (1) {
        if (count_i == n + 1 && count_o == n) break;
        if (count_i < n + 1) {
            pattern.push_back('I');
            count_i++;
        }
        if (count_o < n) {
            pattern.push_back('O');
            count_o++;
        }
    }
}

vector<int> make_fail_func() {
    int pattern_size = pattern.size();
    vector<int> fail(pattern_size, 0);
    for (int i = 1, j = 0; i < pattern_size; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j]) fail[i] = ++j;
    }
    return fail;
}

int find_pattern() {
    vector<int> table = make_fail_func();
    int cnt = 0, parent_size = parent.size(), pattern_size = pattern.size();

    for (int i = 0, j = 0; i < parent_size; ++i) {
        while (j > 0 && parent[i] != pattern[j]) j = table[j - 1];
        if (parent[i] == pattern[j]) {
            if (j == pattern_size - 1) {
                cnt++;
                j = table[j];
            } else {
                j++;
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    make_pattern();

    cin >> m;
    cin >> parent;

    answer = find_pattern();
    cout << answer;

    return 0;
}