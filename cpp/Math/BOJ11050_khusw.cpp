/*  
    BOJ 11050 이항 계수 1
    https://www.acmicpc.net/problem/11050
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    cout << binomialCoefficient(n, k);

    return 0;
}