/*  
    BOJ 2436 공약수
    https://www.acmicpc.net/problem/2436
*/

#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int result = a % b;
    while (result != 0) {
        a = b;
        b = result;
        result = a % b;
    }
    return b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int gcd, lcm, idx;
    cin >> gcd >> lcm;

    lcm /= gcd;
    for (int i = 1; i * i <= lcm; ++i)
        if (lcm % i == 0)              // 약수
            if (GCD(i, lcm / i) == 1)  // 서로소 일때
                idx = i;

    cout << gcd * idx << " " << gcd * (lcm / idx);

    return 0;
}