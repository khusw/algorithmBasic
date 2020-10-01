/*
    달팽이 배열
    9/10 프로그래머스 대회에 나온 문제

    n 이 주어지면 n 에 따른 삼각형 배열을 구현해야함

    예를 들어
    n = 3 이면
    1 0 0
    2 6 0
    3 4 5

    n = 4 이면
    1  0  0  0
    2  9  0  0
    3  10 8  0
    4  5  6  7 이 되는 구조. 

    n = 5 이면
    1  0  0  0  0
    2  12 0  0  0
    3  13 11 0  0
    4  14 15 10 0
    5  6  7  8  9

    DFS 인줄 알았으나 단순한 구현 문제
    (이렇게 방향이 정해져서 탐색하는 문제는 DFS/BFS 가 아닐 가능성이 큼) 아래 오른쪽 좌상대각선 이 세가지가 고정되어 있기 때문임.

    이 문제의 이동 방향은 3가지임
    아래, 오른쪽, 좌상 대각선.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    vector<vector<int>> vec(n + 1, vector<int>(n + 1));
    fill(vec.begin(), vec.end(), vector<int>(n + 1, 0));

    int max_num = (n * (n + 1)) / 2;
    int top = 1;     // 아직 채워지지않은 가장 윗줄 번호를 의미
    int bottom = n;  // 아직 채워지지 않은 가장 아랫쪽 번호를 의미
    int right = 0;   // right 는 층 마다 달라서 현재까지 오른쪽 줄을 채운 횟수로 표현된다
    int left = 1;    // 아직 채워지지 않은 가장 왼쪽줄 번호를 의미
    int num = 1;     // 배열내에 채워넣을 변수값이다.
    int state = 0;   // 어떤 화살표 방향으로 이동할지 표현하기 위한 변수

    while (num <= max_num) {
        if (state == 0) {
            // 아래로 이동
            for (int i = top; i <= bottom; i++) {
                vec[i][left] = num++;
            }
            top++;
            left++;
            state = 1;
        } else if (state == 1) {
            // 오른쪽으로 이동
            for (int i = left; i <= bottom - right; i++) {
                vec[bottom][i] = num++;
            }
            bottom--;
            state = 2;
        } else if (state == 2) {
            // 대각선 좌측 위로 이동
            for (int i = bottom; i >= top; i--) {
                vec[i][i - right] = num++;
            }
            right++;
            top++;
            state = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(vec[i][j]);
        }
    }

    return answer;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr;
    arr = solution(n);

    int size = arr.size();

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}