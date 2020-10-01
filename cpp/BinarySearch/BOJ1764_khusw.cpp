/*
    BOJ 1764 듣보잡
    https://www.acmicpc.net/problem/1764

    듣도 못한 사람
    보도 못한 사람
    각 두 부류의 사람이 주어질때,
    듣도 보도 못한 사람 의 명단을 구하는 프로그램을 작성하는 문제
    (두 집합의 공통 부분을 구하는 그런 문제인듯)

    듣도 못한 사람의 수는 N,
    보도 못한 사람의 수는 M 이며
    듣도 못한 사람의 수만큼 먼저 입력이 주어지고, 
    그 다음 보도 못한 사람의 이름이 입력으로 주어진다.

    듣도 보도 못한 사람의 수 와 명단을 사전순으로 출력해야한다.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> unknown;
vector<string> answer;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    unknown.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> unknown[i];
    }

    // 이진 탐색을 위한 사전순 정렬
    sort(unknown.begin(), unknown.end());

    string str;
    for (int i = 0; i < M; i++) {
        cin >> str;

        if (binary_search(unknown.begin(), unknown.end(), str)) {
            answer.push_back(str);
        }
    }

    int answer_size = answer.size();

    sort(answer.begin(), answer.end());

    cout << answer_size << '\n';

    for (int i = 0; i < answer_size; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}

/*
    이 문제를 풀면서 알게된 두가지 사실
    1. c++ STL 의 vector 의 push_back 을 사용해서 입력값을 받게되면,
    메모리 할당을 2^n 으로 잡게된다.  
    그러나, resize 로 미리 메모리 할당량을 잡아놓으면, 연산 속도도 빨라지고, 메모리도 적게 잡아먹는다.

    2. algorithm 헤더 파일에 
    binary_search 함수가 이미 내장되어 있고, 
    binary_search(vec.begin(), vec.end(), input);
    같이 정의하면, input 이 vec 에 있는 값이라면 true 를 리턴하고 아니라면 false 를 리턴한다.
    다른 문제 풀이 글들을 보다보면, 직접 이진 탐색을 구현하기보다 이런 내장 함수를 더 많이 쓰는듯하다.
    이미 직접 구현할 수 있다는 가정하에서 쓰는것이 좋을 것 같다.
*/