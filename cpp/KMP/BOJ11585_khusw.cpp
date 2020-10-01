/*
    BOJ 11585 속타는 저녁 메뉴
    https://www.acmicpc.net/problem/11585
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string parent, pattern;
char ch;
int cnt;

vector<int> make_pi() {
    int pattern_size = pattern.length();
    vector<int> pi(pattern_size, 0);
    int prefix_index = 0;
    for (int suffix_index = 1; suffix_index < pattern_size; suffix_index++) {
        while (prefix_index > 0 && pattern[suffix_index] != pattern[prefix_index]) {
            prefix_index = pi[prefix_index - 1];
        }
        if (pattern[prefix_index] == pattern[suffix_index]) {
            pi[suffix_index] = ++prefix_index;
        }
    }
    return pi;
}

void KMP() {
    int pattern_size = pattern.length();
    int parent_size = parent.length();
    vector<int> pi = make_pi();
    int pattern_index = 0;
    for (int parent_index = 0; parent_index < parent_size; parent_index++) {
        while (pattern_index > 0 && parent[parent_index] != pattern[pattern_index]) {
            pattern_index = pi[pattern_index - 1];
        }
        if (parent[parent_index] == pattern[pattern_index]) {
            if (pattern_index == pattern_size - 1) {
                pattern_index = pi[pattern_index];
                cnt++;
            } else {
                pattern_index++;
            }
        }
    }
}

void init() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> ch;
        pattern.append(1, ch);
    }

    for (int i = 0; i < N; i++) {
        cin >> ch;
        parent.append(1, ch);
    }
    parent.append(parent);
    parent.pop_back();
    // pop_back() 을 해서 맨 뒷 글자를 제거한 이유
    // 원형 판을 구현하지 않고 편의상 코드를 작성하기 위해서
    // parent 의 크기를 두배로 늘렸을 뿐 실제로는 2배 늘린게 아님
    // 그래서 두배 늘렸을 때
    // I W A N T M E A T I W A N T M E A T
    // I W A N T M E A T I W A N T M E A T
    // 처럼 2번 카운팅 되기 때문에, 오류로 처리될 수 있음.
    // 실제로는 단 한번만 일치하는데 두번 일치한다고 인식됬기 때문에.
}

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    init();
    KMP();
    int num = gcd(cnt, N);
    cout << cnt / num << "/" << N / num;
    return 0;
}