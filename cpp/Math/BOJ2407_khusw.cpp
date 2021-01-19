/*  
    BOJ 2407 Combination
    https://www.acmicpc.net/problem/2407
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 101

using namespace std;

int n, m;
string temp[MAX][MAX];

string big_num(string num1, string num2) {
    long long sum = 0;
    string result;

    while (!num1.empty() || !num2.empty() || sum) {
        // 1 의 자리 부터 추가
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }

        // 합의 결과물을 string 으로
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

// nCr = n-1Cr-1 + n-1Cr
string combination(int n, int r) {
    if (n == r || r == 0) return "1";

    string& result = temp[n][r];
    if (result != "") return result;

    result = big_num(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    cout << combination(n, m) << "\n";

    return 0;
}