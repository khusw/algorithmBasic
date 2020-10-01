/*
    BOJ 2512 예산
    https://www.acmicpc.net/problem/2512
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
ll M;
vector<int> vec_budget;

void bs(int start, int end, ll m) {
    // start 는 예산액의 최저점, end 는 예산액의 최고점, m 은 예산의 배정가능한 예산의 최댓값이다.
    int result;
    while (start <= end) {
        int mid = (start + end) / 2;  // mid 는 예산액의 상한선을 의미함.
        ll temp = 0;                  // temp 는 예산의 상한선을 이용해서 얻은 지방 예산의 총합
        for (int i = 0; i < N; i++) {
            temp += min(vec_budget[i], mid);  // 지방 요청 예산과 예산 예상의 중간지점 간 최소 값을 찾아서 더함
        }
        if (temp <= m) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }
    cout << result << '\n';
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int max_budget = 0;
    for (int i = 0; i < N; i++) {
        ll budget;
        cin >> budget;
        vec_budget.push_back(budget);
        max_budget = max(max_budget, vec_budget[i]);
        // 요청한 지방 예산중 가장 큰 값을 end 값으로 지정
    }

    cin >> M;
    bs(0, max_budget, M);  // 시작은 0 부터 해서 max_budget 까지 이분탐색
    return 0;
}