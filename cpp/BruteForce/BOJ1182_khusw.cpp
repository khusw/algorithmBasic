/* 
    BOJ 1182 부분수열의 합
    https://www.acmicpc.net/problem/1182
*/

#include <iostream>
#define MAX 20

using namespace std;

int N, S, cnt, sum;
int arr[MAX];

void cnt_parital_sum(int index, int sum) {
    if (index == N) return;
    if (sum + arr[index] == S) cnt++;
    cnt_parital_sum(index + 1, sum);
    cnt_parital_sum(index + 1, sum + arr[index]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cnt_parital_sum(0, 0);
    cout << cnt;
    return 0;
}