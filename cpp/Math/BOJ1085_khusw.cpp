/*
    BOJ 1085 직사각형에서 탈출
    https://www.acmicpc.net/problem/1085
*/

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int x, y, w, h, answer;

int distance() {
    int result;

    // 왼쪽 (0, y) 와 (x, y) 사이의 거리
    int left = sqrt(pow((x - 0), 2) + pow((y - y), 2));

    // 오른쪽 (x, y) 와 (w, y) 사이의 거리
    int right = sqrt(pow((w - x), 2) + pow((y - y), 2));

    // 위쪽 (x, y) 와 (x, h) 사이의 거리
    int top = sqrt(pow((x - x), 2) + pow((h - y), 2));

    // 아래쪽 (x, 0) 와 (x, y) 사이의 거리
    int bottom = sqrt(pow((x - x), 2) + pow((y - 0), 2));

    result = min(left, min(right, min(top, bottom)));
    return result;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> x >> y >> w >> h;
    answer = distance();

    cout << answer;

    return 0;
}