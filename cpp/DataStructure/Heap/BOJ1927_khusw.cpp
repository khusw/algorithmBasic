/*
    BOJ 1927 최소 힙
    https://www.acmicpc.net/problem/1927

    1. 배열에 값을 넣는다
    2. 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거한다.

    를 구현하는 프로그램을 작성해야한다.

    힙은 보통 우선순위 큐와 같이 구현되는것이 일반적임

    c++ STL 에서 제공하는 기본 priority_queue 의 경우
    선언시에 다음과 같이 선언한다.

    priority_queue<type, container, compare> 로 선언하며,
    type 의 경우 말 그대로 자료형 설정
    contianer 의 경우, vector 같은 컨테이너를 의미하고,
    compare 는 less<T> 와 greater<T> 가 있는데, 전자는 Max Heap 이며, 후자는 Min Heap 이다.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (!(x) && pq.empty()) {
            // 비어 있는데 0 을 넣은 경우
            cout << 0 << '\n';
        } else if (!(x)) {
            cout << pq.top() << '\n';
            pq.pop();
        } else {
            pq.push(x);
        }
    }

    return 0;
}