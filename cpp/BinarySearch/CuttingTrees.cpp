/*
    BOJ 2805 나무 자르기
    https://www.acmicpc.net/problem/2805

    - 참조
    https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220777333252&proxyReferer=https:%2F%2Fwww.google.com%2F

    - 주의할점
    : 이런류의 문제들은 입력 케이스가 크게 나오기 때문에
    int 로 선언하지말고 long long 으로 선언해서 처리하는게 편하다. (아주 큰 값이 나와야 이분탐색을 제대로 썼는지 파악할 수 있기 때문)
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
ll M;
vector<ll> tree_list;

void binary_search(ll start, ll end) {
    while (start + 1 < end) {
        ll mid = (start + end) / 2;  // mid 는 변동된 H 값을 의미.
        ll temp = 0;                 // temp 는 sigma(hi) 의 값.
        for (int i = 0; i < N; i++) {
            if (tree_list[i] - mid > 0) {
                temp = temp + (tree_list[i] - mid);
            }
        }

        if (temp >= M) {
            // 우측 이분 탐색
            start = mid;
        } else {
            // 좌측 이분 탐색
            end = mid;
        }
    }
    cout << start << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll tree;
        cin >> tree;
        tree_list.push_back(tree);
    }

    binary_search(0, 1000000000);
    return 0;
}