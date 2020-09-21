/*
    BOJ 1107 리모컨
    https://www.acmicpc.net/problem/1107
*/

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int INF = 1000007;
int broken[10];
int N, M;

// 리모컨의 번호를 눌러서 이동할 수 있는 위치인지 파악하는 함수
// 예제 입력 1 에서 5459 가 이 함수를 통과함.
bool possible(int k) {
    if (k == 0)
        return broken[0] ? false : true;

    while (k) {
        if (broken[k % 10] == 1) return false;
        k /= 10;
    }
    return true;
}

int find() {
    int ret = abs(N - 100);  // 입력값 대비 현 위치 간의 거리 계산을 한 변수
    int temp;                // 이 변수는 i 번째의 수가 몇번 입력되야 하는지를 표현한 임시 변수
    int inf = N * 2 - 100;   // 최대 2배에 시작 지점 100 을 뺀 값을 담음.
    if (inf < 100)
        inf = 100;

    if (M == 10)  // 모든 숫자 버튼이 망가진 경우. (base case)
        return ret;

    // N 보다 더 큰 수로 버튼 이동
    for (int i = N; i <= inf; i++) {
        temp = to_string(i).length() + abs(i - N);
        if (possible(i)) {
            ret = min(temp, ret);
            break;
        }
    }

    // N 보다 더 작은 수로 버튼 이동
    for (int i = N; i >= 0; i--) {
        temp = to_string(i).length() + abs(i - N);
        if (possible(i)) {
            ret = min(temp, ret);
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int temp;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        broken[temp] = 1;
    }
    cout << find() << '\n';
    return 0;
}