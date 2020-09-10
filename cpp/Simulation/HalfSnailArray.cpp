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
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    vector<vector<int>> vec(n, vector<int>(n));
    fill(vec.begin(), vec.end(), vector<int>(0, 0));

    int value = 1;  // 배열에 넣을 값.
    int cnt = n;    // n, n - 1, n - 2, .... 1 값으로 점점 하락하면서 value 를 넣어야함.
    int col = 0;
    int row = -1;

    while (cnt > 0) {
        for (int i = row + 1; i < n; i++) {
            if (vec[i][col] != 0)
                break;
            vec[i][col] = value++;
            row = i;
        }
        cnt--;

        for (int i = col + 1; i < n; i++) {
            if (vec[row][i] != 0)
                break;
            vec[row][i] = value++;
            col = i;
        }
        cnt--;

        while (vec[row][col] != 0 && row > 1 && col > 1 && (row - col) == 0) {
            row--;
            col--;
            vec[row][col] = value++;
        }
        cnt--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] != 0) {
                answer.push_back(vec[i][j]);
            }
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