/*
    BOJ 11279 최대 힙
    https://www.acmicpc.net/problem/11279

    BOJ 1927 문제와 동일하게 풀면된다.
    https://www.acmicpc.net/problem/1927

    힙을 구현할 때는 STL 의 priority_queue<type, container, compare> 를 사용해서 구현하자

    클래스를 직접 정의해서 구현할 수도 있겠지만,
    이게 훨씬 더 빠르게 구현이 가능하다.

    참고로 STL 의 less 는 첫번째 인자가 두번째 인자보다 작으면 true (오름차순)
    greater 는 첫번째 인자가 두번째 인자보다 크면 true 를 리턴하도록 되어 있다. (내림차순)
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

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (!(x) && pq.empty()) {
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