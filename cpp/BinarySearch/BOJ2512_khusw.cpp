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
    int result;
    while (start <= end) {
        int mid = (start + end) / 2;
        ll temp = 0;
        for (int i = 0; i < N; i++) {
            temp += min(vec_budget[i], mid);
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
    }

    cin >> M;
    bs(0, max_budget, M);
    return 0;
}