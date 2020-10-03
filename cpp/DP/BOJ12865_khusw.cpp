/*
    BOJ 12865 평범한 배낭
    https://www.acmicpc.net/problem/12865
*/

#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int N, W;
int prices[101][100001];
int wt[101];
int val[101];

int Knapsack() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i] <= j)
                prices[i][j] = max(val[i] + prices[i - 1][j - wt[i]], prices[i - 1][j]);
            else
                prices[i][j] = prices[i - 1][j];
        }
    }
    return prices[N][W];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << Knapsack();
    return 0;
}