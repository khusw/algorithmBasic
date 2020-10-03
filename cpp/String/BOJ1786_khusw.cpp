/*
    BOJ 1786 찾기
    https://www.acmicpc.net/problem/1786
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> pPos;
int pCount;

vector<int> make_table(string& pattern) {
    int pattern_size = pattern.length();
    vector<int> pi(pattern_size, 0);
    int prefix_index = 0;
    for (int suffix_index = 1; suffix_index < pattern_size; suffix_index++) {
        while (prefix_index > 0 && pattern[prefix_index] != pattern[suffix_index]) {
            prefix_index = pi[prefix_index - 1];
        }
        if (pattern[prefix_index] == pattern[suffix_index]) {
            pi[suffix_index] = ++prefix_index;
        }
    }
    return pi;
}

void KMP(string& parent, string& pattern) {
    int parent_size = parent.length();
    int pattern_size = pattern.length();
    vector<int> pi = make_table(pattern);
    int pattern_index = 0;
    for (int parent_index = 0; parent_index < parent_size; parent_index++) {
        while (pattern_index > 0 && parent[parent_index] != pattern[pattern_index]) {
            pattern_index = pi[pattern_index - 1];
        }
        if (parent[parent_index] == pattern[pattern_index]) {
            if (pattern_index == pattern_size - 1) {
                pattern_index = pi[pattern_index];
                pPos.push_back(parent_index - pattern_size + 2);
                pCount++;
            } else {
                pattern_index++;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string parent, pattern;

    getline(cin, parent);
    getline(cin, pattern);
    KMP(parent, pattern);

    printf("%d\n", pCount);
    for (int i = 0; i < pPos.size(); i++) {
        printf("%d ", pPos[i]);
    }

    return 0;
}