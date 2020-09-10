/*
    BOJ 18870 압축된 좌표
    https://www.acmicpc.net/problem/18870
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> vec;  // value, key
vector<int> answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    vec.resize(N);
    answer.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i].first;  // 값만 입력 받고 인덱스 값은 i 로 처리
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());  // 아무런 compare 함수를 넣지 않으면 pair 의 첫번째 값을 기준으로 오름차순 정렬함.

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int key = vec[i].second;  // 인덱스 값
        int temp = cnt;           // 인덱스 값 변화를 위한 임시 값

        answer[key] = temp;  // 기존의 인덱스를 임시 값으로 변경. (answer 는 인덱스 값만 가지는 변수)
        cnt++;

        while (i < N && vec[i].first == vec[i + 1].first) {
            // 배열의 두 value 값이 동일한 경우, 동일 개체로 취급해야 되서, temp 에 변화를 주지 않고 똑같은 값을 넣어줌.
            ++i;
            key = vec[i].second;
            answer[key] = temp;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}