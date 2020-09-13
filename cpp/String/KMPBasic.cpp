/*
    기본 KMP 알고리즘 코드 작성하기
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> make_table(string& pattern) {
    int pattern_size = pattern.length();
    vector<int> pi(pattern_size, 0);                                           // pi 배열을 0으로 초기화 (0으로 초기화하면 prefix 가 부분 문자열이 되는 경우를 고려하지 않아도 됨, 그래서 suffix_index 가 1 부터 시작하는 것)
    int prefix_index = 0;                                                      // 접두사의 인덱스
    for (int suffix_index = 1; suffix_index < pattern_size; suffix_index++) {  // 접미사의 인덱스
        while (prefix_index > 0 && pattern[prefix_index] != pattern[suffix_index]) {
            // 접두사의 인덱스 0 보다 크다는 뜻은, 이전 단계에서 이미 일치하는 접두사와 접미사가 있었다는 의미가 된다
            // 또한 접미사와 접두사가 일치하지 않을 때, 이 반복문을 돌라는 의미는 더이상 접두사의 인덱스를 늘리지 않겠다는 의미가 된다
            // 일치하는 부분이 여기까지라는 뜻. 그래서 접두사의 인덱스를 다시 초기화 할 필요가 있고,
            // 초기화를 처음부터 다시하는게 아니라 일치했던 부분으로 다시 돌리는 것임 (pi 배열에 일치했던 접두사의 값이 들어가기 때문)
            prefix_index = pi[prefix_index - 1];
        }
        if (pattern[prefix_index] == pattern[suffix_index]) {
            //접두사와 접미사가 일치하면 pi 배열에 들어갈 수 있는 조건이 되는 것.
            // 그리고 인덱스는 항상 0 부터 시작하기 때문에 전위 연산자로 하나 미리 더한 값을 넣어줘야 맞음.
            pi[suffix_index] = ++prefix_index;
        }
    }
    return pi;
}

void KMP(string& parent, string& pattern) {
    vector<int> pi = make_table(pattern);
    int parent_size = parent.length();
    int pattern_size = pattern.length();
    int pattern_index = 0;
    for (int parent_index = 0; parent_index < parent_size; parent_index++) {
        while (pattern_index > 0 && parent[parent_index] != pattern[pattern_index]) {
            pattern_index = pi[pattern_index - 1];
        }
        if (parent[parent_index] == pattern[pattern_index]) {
            if (pattern_index == pattern_size - 1) {
                printf("%d 에서 발견 \n", parent_index - pattern_size + 2);
                pattern_index = pi[pattern_index];
            } else {
                pattern_index++;
            }
        }
    }
}

int main() {
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    vector<int> pi = make_table(pattern);
    auto print = [](const int& n) { cout << n << " "; };
    for_each(pi.begin(), pi.end(), print);
    return 0;
}