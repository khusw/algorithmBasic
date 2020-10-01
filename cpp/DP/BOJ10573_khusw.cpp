/*
    BOJ 10573 증가하는 수
    https://www.acmicpc.net/problem/10573

    증가하는 수란,
    각 자리의 수가 증가하거나 같은 경우를 말한다
    예를들면
    123 은 증가하는 수 이지만,
    101 은 증가하는 수가 아니다. (1 > 0 < 1 이므로)

    입력은 테스트 케이스 수 가 주어지고,
    테스트 케이스는 자연수로 주어지며, 자릿수의 총 갯수가 80자리 수를 넘지 못한다.

    출력은 각 테스트 케이스 별로 판별을 하고
    증가하는 수가 아니라면 -1 을 출력하고,
    증가하는 수라면 그 수 보다 작은 증가하는 정수의 갯수를 출력.

    일단 한자리수의 경우 자신보다 1적은 값을 출력하면 됨.
    두자리수 부터가 문제인데, 이 문제는 감소하는 수 때 풀었던 것 처럼 풀면됨
*/

#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int T;
vector<ll> vec;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    int num;

    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num < 10) {
                }
    }

    return 0;
}