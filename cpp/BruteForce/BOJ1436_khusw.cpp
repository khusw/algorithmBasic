/*
    BOJ 1436 영화감독 숌
    https://www.acmicpc.net/problem/1436
*/

#include <iostream>

using namespace std;

int N, i, tmp, flag, cnt;
// 입력 N, N번째의 수를 나타내는 i,
// 666 이 들어갔는지 확인을 하기 위한 임시 변수 tmp
// 666 을 발견했음을 나타내는 변수 flag
// 카운팅을 위한 변수 cnt

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    while (++i) {
        tmp = i, flag = 0;
        while (tmp) {
            if (tmp % 1000 == 666) flag = 1;
            tmp /= 10;
        }

        if (flag) {
            cnt++;
            if (cnt == N) break;
        }
    }

    cout << i;

    return 0;
}

/*
    이 문제는 666, 1666, 2666, 3666, 4666, 5666, 6666 이 되는게 아니라
    6660 의 순서로 바뀌어서 진행됨 (문제에 설명에도 없는게 함정..)
    이 문제의 가장 핵심은 666 가 최소 3번 들어갔느냐 보는거고
    666가 3번 들어갔다면 카운팅을 하고 다음 숫자로 넘어가는게 핵심
*/